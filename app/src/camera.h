#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QCameraImageCapture>

#define BUFSIZE 128

class Camera : public QCamera
{
public:
    Camera();
    void connectToCamera(); //throws exception if unable to connect
    void processFrames();
    int retrieveCameraNames();

private:
    QCamera *camera;
    QCameraImageCapture *imageCapture;
    QStringList *cameraList;
};

#endif // CAMERA_H
