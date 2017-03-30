#include "camera.h"
#include <QCameraViewfinder>
#include <QCameraInfo>

using namespace std;

Camera::Camera()
{
    retrieveCameraNames();
//    camera = new QCamera(QCameraInfo::defaultCamera());
    imageCapture = new QCameraImageCapture(camera);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
}


int Camera::retrieveCameraNames()
{
    string cmd ="for I in /sys/class/video4linux/*; do cat $I/name; done";

        char buf[BUFSIZE];
        FILE *fp;

        if ((fp = popen(cmd.c_str(), "r")) == NULL) {
            qDebug() << "Error opening pipe!\n";
            return -1;
        }

        while (fgets(buf, BUFSIZE, fp) != NULL) {
            // Do whatever you want here...
            // TODO: store OUTPUT as list of strings || as QStringList
            camera = new QCamera(buf);
            qDebug() << "OUTPUT: " << buf;
        }

        if(pclose(fp))  {
            qDebug() << "Command not found or exited with error status\n";
            return -1;
        }
//        string cam = "HP Truevision HD";

        return 0;
}
