#ifndef MYPICLABEL_H
#define MYPICLABEL_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QMessageBox>
#include <QPoint>
#include <iostream>
#include <QPixmap>
 #include <QDebug>
using namespace std;
class myframeview : public QGraphicsView
{
    Q_OBJECT
public:
    explicit myframeview(QWidget *parent = 0);
     QPoint leftClickPosition;
     QPoint rightPressPosition;
     QPoint rightReleasePosition;
     static bool isRightPressed;
     static int ROI_X;
     static int ROI_Y;
     static int ROI_Width;
     static int ROI_Height;
signals:

public slots:
protected:
    void mousePressEvent(QMouseEvent *e);
    //void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MYPICLABEL_H
