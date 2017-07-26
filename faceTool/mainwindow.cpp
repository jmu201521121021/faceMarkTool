#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "toolbox.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//bool isSplitButtonCliked = false;
bool isBegin = false;   //控制是否开始读取视屏流
void MainWindow::on_splitBuntton_clicked()
{

}

void MainWindow::on_startButton_clicked()
{
    if(isBegin == false)
    {
        isBegin = true;
        //从视屏中读取特定帧frame
        cv::Mat frame = readVideo(1);
        //把获得的frame送进网络处理,获得位置faceLoaction

        vector<Rect> faceLocation = sendFrameToOpenCv(frame);


        //挂载当前帧frame,要先转化frame的格式，Mat -->  QImage
        QImage qImg = changeFrameFormat(frame);
        QGraphicsScene *sceneLeft = new QGraphicsScene;
        sceneLeft->clear();
        sceneLeft->addPixmap(QPixmap::fromImage(qImg));
        ui->srcImage->setScene(sceneLeft);
        ui->srcImage->show();
        //load end
    }
    //开始之后，又点击一次＂开始＂按钮，TODO:
    if(isBegin == true)
    {

    }
}

