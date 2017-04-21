#include "pump.h"
#include "qdebug.h"

Pump::Pump()
    : m_connected(false),
      m_flowrate(0)
{

}

int Pump::connectPump()
{
    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4");

    return 0;
}


int Pump::startPump()
{
    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 \"start\"");
    return 0;
}

int Pump::stopPump()
{
    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 \"stop\"");
    return 0;
}

int Pump::setRate(double flowrate)
{
    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 \"set rate "+flowrate+"\"");
    return 0;
}
