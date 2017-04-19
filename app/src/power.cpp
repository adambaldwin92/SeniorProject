#include "power.h"

Power::Power(QObject *parent)
    : QObject(parent),
      m_power_connected(false)
{
    // connect work signals->slots
//    QObject::connect(this, SIGNAL(camera_connected()), this, SLOT()
    //^^ might not need if using bool flag...
}

void Power::connectPower()
{
    qDebug()<<"Power::connectPower called from: "
           << QThread::currentThreadId();
    // signal bool flag to allow onTimer Process to start reading data

    bool success = true; //should actually be return value of connection attempt

    if(success)
    {
        qDebug()<<"Sucessfully connected to Power\n";
        m_power_connected = true;
    }
    else // should throw error/exception or wait for connection to establish
    {
        qDebug()<<"ERROR: cannot connect to Power";
    }

}


void Power::readVoltage()
{
    qDebug()<<"Power::readVoltage called from: "
       << QThread::currentThreadId();
    if (power_connected())
    {
        int voltage = 3;
        m_voltage = voltage;
    }
    else
    {
        qDebug()<<"Power source disconnected..";
    }

}

/*
 * Power::changeVoltage may need mutex so
 * voltage value doesnt become corrupt
 */
void Power::updatePower(int voltage)
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
            emit voltageChanged(voltage);
        }
        else
        {
            qDebug()<<"no change in voltage";
            // do nothing
        }
    }
    else
    {
        qDebug()<<"Power not connected!";
        // do nothing here
    }

}
