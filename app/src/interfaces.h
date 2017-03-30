#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>


QT_BEGIN_NAMESPACE
 class QObject;
 class QWidget;
 class QThread;
 class QCameraInfo;
 class QCamera;
 class QCameraImageCapture;
 class QAbstractSocket::SocketError;
QT_END_NAMESPACE


class ClientInterface
{
public:
    virtual ~ClientInterface() {}

    virtual void someAbstractMethod() = 0;

private slots:
    virtual void requestNewData() = 0;
    virtual void readData() = 0;
    virtual void displayError(QAbstractSocket::SocketError socketError) = 0;
    virtual void sessionOpened() = 0;

private:

};


class ServerInterface
{
public:
    virtual ~ServerInterface() {}

    virtual void someAbstractMethod() = 0;
};


class ThreadInterface
{
public:
    virtual ~ThreadInterface() {}

    virtual void run() = 0;
};


class CameraInterface
{
public:
    virtual ~CameraInterface() {}

    virtual void connectToCamera() = 0;
    virtual void processFrames() = 0;

private:
    QCamera *camera;
    QCameraImageCapture *imageCapture;
};

class PowerInterface
{
public:
    virtual ~PowerInterface() {}

    virtual int voltage() = 0;

public slots:
    virtual void setVoltage(int volt) = 0;

signals:
    virtual void voltageChanged(int newVolt) = 0;

private:
    int voltage;
};

QT_BEGIN_NAMESPACE

#define ClientInterface_iid "SeniorProject.ClientInterface"
Q_DECLARE_INTERFACE(ClientInterface, ClientInterface_iid)

#define ServerInterface_iid "SeniorProject.ServerInterface"
Q_DECLARE_INTERFACE(ServerInterface, ServerInterface_iid)

#define ThreadInterface_iid "SeniorProject.ThreadInterface"
Q_DECLARE_INTERFACE(ThreadInterface, ThreadInterface_iid)

#define CameraInterface_iid "SeniorProject.CameraInterface"
Q_DECLARE_INTERFACE(CameraInterface, CameraInterface_iid)

#define PowerInterface_iid "SeniorProject.PowerInterface"
Q_DECLARE_INTERFACE(PowerInterface, PowerInterface_iid)

QT_END_NAMESPACE

#endif // INTERFACES_H
