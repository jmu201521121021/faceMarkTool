#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "QImage"
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include <QtGui>
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>
#include <QTextCodec>
#include "vector"
using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_splitBuntton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_nextButton_clicked();




    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;

protected:
    //void mousePressEvent(QMouseEvent *e);	//--鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e);	//--鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);	//--鼠标释放（松开）事件
    void mouseDoubleClickEvent(QMouseEvent *e);	//--鼠标双击事件

};

#endif // MAINWINDOW_H
