#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>

#include <QMessageBox>
#include <QPalette>

#include <QtWidgets>

//#include"uc480.h"

Q_DECLARE_METATYPE(QCameraInfo)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    camera(0),
    imageCapture(0),
    mediaRecorder(0),
    isCapturingImage(false),
    applicationExiting(false)
{

//        int* pnNumCams;
//       int n = is_GetNumberOfCameras(pnNumCams);
//        qDebug() << "number of cameras: " << n ;

    ui->setupUi(this);

    //Camera devices:

    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras()) {
        QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);

        ui->menuDevices->addAction(videoDeviceAction);
    }

    connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));

    setCamera(QCameraInfo::defaultCamera());


}

MainWindow::~MainWindow()
{
    delete mediaRecorder;
    delete imageCapture;
    delete camera;
}

void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{
    delete imageCapture;
    delete mediaRecorder;
    delete camera;

    camera = new QCamera(cameraInfo);


    mediaRecorder = new QMediaRecorder(camera);
    imageCapture = new QCameraImageCapture(camera);

    mediaRecorder->setMetaData(QMediaMetaData::Title, QVariant(QLatin1String("Test Title")));

    camera->setViewfinder(ui->viewfinder);

    camera->start();
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if (event->isAutoRepeat())
        return;

    switch (event->key()) {
    case Qt::Key_CameraFocus:
        displayViewfinder();
        camera->searchAndLock();
        event->accept();
        break;
    case Qt::Key_Camera:
        event->accept();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    switch (event->key()) {
    case Qt::Key_CameraFocus:
        camera->unlock();
        break;
    default:
        QMainWindow::keyReleaseEvent(event);
    }
}


void MainWindow::startCamera()
{
    camera->start();
}

void MainWindow::stopCamera()
{
    camera->stop();
}



void MainWindow::updateCameraDevice(QAction *action)
{
    setCamera(qvariant_cast<QCameraInfo>(action->data()));
}

void MainWindow::displayViewfinder()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::closeEvent(QCloseEvent *event)
{
    if (isCapturingImage) {
        setEnabled(false);
        applicationExiting = true;
        event->ignore();
    } else {
        event->accept();
    }

}
