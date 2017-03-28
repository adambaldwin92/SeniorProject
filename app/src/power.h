#ifndef POWER_H
#define POWER_H

#include <QTcpSocket>
#include "client.h"
#include "server.h"
#include "thread.h"

//class Power : public Server
class Power
{
private:
    int PORT;
    double voltage;
    QTcpSocket *socket;

public:
    Power();
    void connectPower();
    double getVolt();
    void readVoltage();
    void writeVoltage(double v);
    ~Power();
};

#endif // POWER_H
