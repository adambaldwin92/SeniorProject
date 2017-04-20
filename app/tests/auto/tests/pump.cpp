#include "pump.h"
#include "qdebug.h"

Pump::Pump()
    : m_connected(false),
      m_flowrate(0)
{

}

int Pump::connectPump()
{
//    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4");

    return 0;
}


int Pump::startPump()
{
    return 0;
}

int Pump::stopPump()
{
    return 0;
}

int Pump::setRate(double flowrate)
{
    return 0;
}
