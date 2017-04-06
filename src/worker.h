#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QtCore>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

    bool camera_connected() const { return m_camera_connected; }
    bool power_connected() const { return m_power_connected; }
    int voltage() const { return m_voltage; }

signals:
    void voltageChanged(int voltage);
    void frameRecieved(int frame); //change param type from int to img

public slots:
    void connectCamera(); //on QThread::started() signal
    void connectPower(); //on QThread::started() signal


    void cameraTimerEvent(); // on QTimer::timeout() signal
    void powerTimerEvent(); // on voltageChanged signal

    void processFrame();
    void setVoltage(int voltage);


private:
    bool m_camera_connected;
    bool m_power_connected;

    int m_voltage;
    //TODO: add img frame container (look up what opencv suggests)

};

#endif // WORKER_H
