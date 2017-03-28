#include "camera.h"
#include <QCameraViewfinder>
#include <QCameraInfo>

Camera::Camera()
{
    camera = new QCamera(QCameraInfo::defaultCamera());
    imageCapture = new QCameraImageCapture(camera);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
}
