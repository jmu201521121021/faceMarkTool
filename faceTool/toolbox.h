#ifndef TOOLBOX_H
#define TOOLBOX_H



void loadPictureToLeftView(cv::Mat frame);
void showFrame();
void moveRectFrame();
QImage changeFrameFormat(Mat frame);
vector<Rect> sendFrameToOpenCv(Mat frame);
Mat readVideo(int counter);

#endif // TOOLBOX_H
