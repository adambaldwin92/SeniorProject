#ifndef PUMP_H
#define PUMP_H

#include <Windows.h>
#include "interfaces.h"

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

};
#endif // PUMP_H
