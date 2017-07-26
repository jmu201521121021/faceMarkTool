#include "mainwindow.h"
#include "toolbox.h"
//从视屏中读取帧，返回获取的帧,counter表示第几帧
Mat readVideo(int counter)
{
    String videoPath = "/media/jinshan/0EA21AAE0EA21AAE/ubuntu/png/0108.avi";
    Mat frame;
    Mat dst;
    VideoCapture capture(videoPath);
    if(!capture.isOpened())
    {
        cout<<"fail to open video!"<<endl;
    }
    capture.set(CV_CAP_PROP_POS_FRAMES, counter);
    capture>>frame;
   // capture.release();
    cv::resize(frame, dst, Size(701,481));  //TODO:
    return dst;
}

//把当前帧送进opencv中检测
vector<Rect> sendFrameToOpenCv(Mat frame)
{
    Mat grayFrame;
    std::vector<Rect> faceLocation;
    CascadeClassifier faceCascade;
    faceCascade.load("/xml/haarcascade_frontalface_alt.xml"); //加载haar级联文件人脸分类器

    if(!faceCascade.empty())
    {
        cvtColor(frame, grayFrame, CV_BGR2GRAY);  //rgb类型转换为灰度类型
        equalizeHist(grayFrame, grayFrame); //直方图均衡化
        faceCascade.detectMultiScale(grayFrame, faceLocation, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(1, 1));
    }
    return faceLocation;    //返回人脸位置,TODO:什么类型
}

//转换frame的格式，让graphics view控件可以显示
QImage changeFrameFormat(Mat frame)
{
    Mat rgb;
    QImage qImg;
    cvtColor(frame, rgb, CV_BGR2RGB);
    qImg = QImage((const uchar*)(rgb.data),
                    rgb.cols,rgb.rows,
                    rgb.cols*rgb.channels(),
                    QImage::Format_RGB888);
    return qImg;
}

void showFrame()
{

}

void moveRectFrame()
{

}

//根据获得的位置(网络获得的人脸位置或者手动获得的人脸位置)产生框
void createRect(vector<Rect> faceLocation)
{
}

