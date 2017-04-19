#ifndef CAMERA_H
#define CAMERA_H


#include <QObject>
#include <QtCore>

//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//using namespace cv;

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = 0);

    bool connected() const { return m_connected; }
//    Mat current_frame() const { return m_frame; }
signals:
//    void frameRecieved(Mat frame);
    void disconnect();

public slots:
    void connectCamera(); //on QThread::started() signal
    void disconnectCamera();
//    int readFrame(); // on QTimer::timeout() signal

//    void processFrame(Mat frame);

private:
    bool m_connected;
//    Mat m_frame;

};
#endif // CAMERA_H
