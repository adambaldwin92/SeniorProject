#include "pump.h"
#include "qdebug.h"

Pump::Pump()
{

}

void Pump::connectPump()
{
    if (serial.Open(2, 9600))
        qDebug() << "Connected to COM port!";
    else
        qDebug() << "Failed to open pump port!";

}
