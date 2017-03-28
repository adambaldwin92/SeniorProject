#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraViewfinder>
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectCamera();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectCamera()
{
    camera = new QCamera(QCameraInfo::defaultCamera());
//    camera = new Camera();

    camera->setViewfinder(ui->viewfinder);

    imageCapture = new QCameraImageCapture(camera);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
}
