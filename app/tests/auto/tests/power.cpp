#include "power.h"

//Power::Power(iPower *parent)
//    : iPower(parent),
//      m_power_connected(false)
//{
//}
Power::Power()
    : m_power_connected(false)
{
}

int Power::connectPower()
{
    qDebug()<<"Power::connectPower called from: "
           << QThread::currentThreadId();
    // signal bool flag to allow onTimer Process to start reading data

    bool success = true; //should actually be return value of connection attempt

    if(success)
    {
        qDebug()<<"Sucessfully connected to Power\n";
        m_power_connected = true;
        return 0;
    }
    else // should throw error/exception or wait for connection to establish
    {
        qDebug()<<"ERROR: cannot connect to Power";
        return -1;
    }

}


int Power::readVoltage()
{
    qDebug()<<"Power::readVoltage called from: "
       << QThread::currentThreadId();
    if (power_connected())
    {
        int voltage = 3;
        m_voltage = voltage;
        return 0;
    }
    else
    {
        qDebug()<<"Power source disconnected..";
        return -1;
    }

}

/*
 * Power::changeVoltage may need mutex so
 * voltage value doesnt become corrupt
 */
int Power::writeVoltage(double voltage)
{
    qDebug()<<"Power::changeVoltage called from: "
       << QThread::currentThreadId();

    if(power_connected())
    {
        qDebug()<<"PowerTimerEvent read in current voltage input";

        //TODO: replace mock value with actual read() method

        if(voltage != m_voltage)
        {
            qDebug()<<"emit voltageChanged";
            // TODO: write new voltage to labjack
            return 0;
        }
        else
        {
            qDebug()<<"no change in voltage";
            // do nothing
            return 0;
        }
    }
    else
    {
        qDebug()<<"Power not connected!";
        // do nothing here
        return -1;
    }

}
