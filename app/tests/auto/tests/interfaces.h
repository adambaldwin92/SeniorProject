#ifndef INTERFACES_H
#define INTERFACES_H

#include <QObject>
#include<QDebug>
#include<QThread>

class iPump : public QObject
{
    Q_OBJECT
public:
    virtual ~iPump() {}
public slots:
    virtual int connectPump() = 0;
    virtual int startPump() = 0;
    virtual int stopPump() = 0;
    virtual int setRate(double flowrate) = 0;
};

class iPower : public QObject
{
    Q_OBJECT
public:
    virtual ~iPower() {}
public slots:
    virtual int connectPower()=0;
    virtual int writeVoltage(double voltage)=0;
    virtual int readVoltage()=0;
};

class iCamera : public QObject
{
    Q_OBJECT
public:
    virtual ~iCamera() {}
public slots:
    virtual int connectCamera()=0;
};


#endif // INTERFACES_H
