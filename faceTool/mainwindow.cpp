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
bool isHandle = false;  //手动裁剪
long counter = 2;
void MainWindow::on_splitBuntton_clicked()
{
    if(isHandle == false)
    {
        isHandle = true;
    }
}


void MainWindow::on_startButton_clicked()
{
    if(isBegin == false)
    {
        isBegin = true;
        //从视屏中读取特定帧frame
        cv::Mat frame = readVideo(1);
        //把获得的frame送进网络处理,获得位置faceLoaction
        if(ui->checkOpencv->isChecked())
        {
            vector<Rect> faceLocation = sendFrameToOpenCv(frame);
        }
        else if(ui->checkMtcnn->isChecked())
        {
            std::cout<<"mtcnn!"<<endl;
        }
        else if(ui->checkTiny->isChecked())
        {
            std::cout<<"Tiny-face"<<endl;
        }
        else if(ui->checkOther->isChecked())
        {
            std::cout<<"other!"<<endl;
        }
        else
        {
            std::cout<<"please select one first!"<<endl;
        }
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


void MainWindow::on_stopButton_clicked()
{

}


//点击＂下一张＂按钮，执行下一帧图片
void MainWindow::on_nextButton_clicked()
{
    //从视屏中读取特定帧frame
    int fpInterval = 30;
    fpInterval = ui->fpNumber->text().toInt(); //fpInterval  为获得的帧率
    std::cout<<fpInterval<<endl;
    counter = counter + fpInterval;
    cv::Mat frame = readVideo(counter);
    //把获得的frame送进网络处理,获得位置faceLoaction
    if(ui->checkOpencv->isChecked())
    {
        vector<Rect> faceLocation = sendFrameToOpenCv(frame);
    }
    else if(ui->checkMtcnn->isChecked())
    {
        std::cout<<"mtcnn!"<<endl;
    }
    else if(ui->checkTiny->isChecked())
    {
        std::cout<<"Tiny-face"<<endl;
    }
    else if(ui->checkOther->isChecked())
    {
        std::cout<<"other!"<<endl;
    }
    else
    {
        std::cout<<"please select one first!"<<endl;
    }
    //挂载当前帧frame,要先转化frame的格式，Mat -->  QImage
    QImage qImg = changeFrameFormat(frame);
    QGraphicsScene *sceneLeft = new QGraphicsScene;
    sceneLeft->clear();
    sceneLeft->addPixmap(QPixmap::fromImage(qImg));
    ui->srcImage->setScene(sceneLeft);
    ui->srcImage->show();
    //load end
}
/*------------------mouse caozuo ---------------------*/
//--鼠标按下事件

void MainWindow::mouseMoveEvent(QMouseEvent *e)//--鼠标移动事件
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)	//--鼠标释放（松开）事件
{

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)	//--鼠标双击事件
{

}
void MainWindow::on_saveButton_clicked()
{

}

