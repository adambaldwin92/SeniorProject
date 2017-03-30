#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QCameraViewfinder>
#include <QCameraInfo>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera = new Camera();
//    camera->connectCamera();
}



MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::connectCamera()
//{
//    camera = new Camera();


//    camera->setViewfinder(ui->viewfinder);

//    imageCapture = new QCameraImageCapture(camera);

//    camera->setCaptureMode(QCamera::CaptureStillImage);
//    camera->start();
//}
