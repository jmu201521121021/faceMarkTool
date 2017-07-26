#include "myframeview.h"
int myframeview::ROI_X = 0;
int myframeview::ROI_Y = 0;
int myframeview::ROI_Width = 0;
int myframeview::ROI_Height = 0;
bool myframeview::isRightPressed = false;
myframeview::myframeview(QWidget *parent) :
    QGraphicsView(parent)
{

}

void myframeview::mousePressEvent(QMouseEvent *e)
{
    this->setCursor(Qt::CrossCursor);
    if(e->button() == Qt::LeftButton)
    {
        rightPressPosition = e->pos();
        leftClickPosition = e->pos();
    }
    //TODO: MUSU IN AREA
    else if(e->button() == Qt::RightButton)
    {
        rightPressPosition = e->pos();
        isRightPressed = true;
    }
    update();
}
void myframeview::mouseReleaseEvent(QMouseEvent *e)
{
    this->setCursor(Qt::CrossCursor);
    if(e->button() == Qt::RightButton && isRightPressed == true)
    {
        rightReleasePosition = e->pos();
        //TODO:re-painter
    }
}

void myframeview::paintEvent(QPaintEvent *e)
{
      std::cout<<"sa";
      ROI_X=rightPressPosition.x();
      ROI_Y=rightPressPosition.y();
      ROI_Width=rightPressPosition.x()-leftClickPosition.x();
      ROI_Height=rightPressPosition.y()-leftClickPosition.y();
      QPainter painter(this->viewport());
      painter.setPen(QColor(Qt::red));
      painter.drawRect(ROI_X,ROI_Y,ROI_Width,ROI_Height);
      QGraphicsView::paintEvent(e);
}
