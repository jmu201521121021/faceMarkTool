#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include<QtGui>
#include <QApplication>
#include<opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
