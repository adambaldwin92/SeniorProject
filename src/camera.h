#ifndef CAMERA_H
#define CAMERA_H


#include <QObject>
#include <QtCore>

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = 0);

    bool camera_connected() const { return m_camera_connected; }

signals:
    void frameRecieved(int frame); //change param type from int to img

public slots:
    void connectCamera(); //on QThread::started() signal
    void cameraTimerEvent(); // on QTimer::timeout() signal
    void processFrame();

private:
    bool m_camera_connected;
    //TODO: add img frame container (look up what opencv suggests)

};

#endif // CAMERA_H
