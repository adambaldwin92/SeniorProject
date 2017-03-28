#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QCameraImageCapture>


class Camera : public QCamera
{
public:
    Camera();
    void connectToCamera(); //throws exception if unable to connect
    void processFrames();

private:
    QCamera *camera;
    QCameraImageCapture *imageCapture;
};

#endif // CAMERA_H
