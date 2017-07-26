#include "mainwindow.h"
#include "toolbox.h"


//extern bool isSplitButtonCliked;

//void test()
//{
//    if(isSplitButtonCliked)
//    {
//        printf("ok!");
//    }
//}


//从视屏中读取帧，返回获取的帧,counter表示第几帧
Mat readVideo(int counter)
{
    String videoPath = "/home/liutao/workspace/ropeok/0108.avi";
    //VideoCapture capture;
    Mat frame;

//    CvCapture *video = cvCreateFileCapture(videoPath);
//    cvSetCaptureProperty(video, CV_CAP_PROP_POS_FRAMES, counter);
//    IplImage *tmp = cvQueryFrame(video);
//    cvReleaseCapture(&tmp);
//    frame = cv::Mat(tmp);

    VideoCapture capture(videoPath);
    if(!capture.isOpened())
    {
        cout<<"fail to open video!"<<endl;
    }
    capture.set(CV_CAP_PROP_POS_FRAMES, counter);
    capture>>frame;

    return frame;
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


//void loadPictureToLeftView(Mat frame)
//{
//    QImage qImg = changeFrameFormat(frame);

//}

void showFrame()
{

}

void moveRectFrame()
{

}
