#ifndef PUMP_H
#define PUMP_H

#include "interfaces.h"
#include<qprocess.h>

//using namespace boost::process;

//namespace bp =  ::boost::process;

class Pump : public iPump
{
public:
    Pump();
    bool connected() const{ return m_connected; }
    double flowrate() const { return m_flowrate; }

    int connectPump();
    int startPump();
    int stopPump();
    int setRate(double flowrate);

private:
    bool m_connected;
    double m_flowrate;
    QString program = "C:\\Program Files\\PuTTY\\putty.exe";
    QStringList arguments;
    QProcess *myProcess;
};
#endif // PUMP_H
