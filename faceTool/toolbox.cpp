#include "toolbox.h"
#include "mainwindow.h"
void loadPictureToLeftView()
{

}

void on_splitBuntton_clicked()
{

}

void showFrame()
{

}

void moveRectFrame()
{

}
QImage bgrTorgb(Mat frame){
    Mat rgb;
    QImage qImg;
    cvtColor(frame,rgb,CV_BGR2RGB);
    qImg = QImage((const uchar*)(rgb.data),
             rgb.cols,rgb.rows,
             rgb.cols*rgb.channels(),
             QImage::Format_RGB888);
    return qImg;
}
