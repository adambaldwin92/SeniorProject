#include "power.h"

Power::Power(QObject *parent)
    : QObject(parent),
      m_power_connected(false)
{

}

Power::~Power()
{

}

void Power::connectPower()
{
    qDebug()<<"\nWorker::connectPower called from: "
           << QThread::currentThreadId();
    // signal bool flag to allow onTimer Process to start reading data

    bool success = true; //should actually be return value of connection attempt

    if(success)
    {
        qDebug()<<" Sucessfully connected to Power\n";
        m_power_connected = true;
    }
    else // should throw error/exception or wait for connection to establish
    {
        qDebug()<<" ERROR: cannot connect to Power";
    }

}

/*
 * Worker::changeVoltage may need mutex so
 * voltage value doesnt become corrupt
 */
void Power::powerTimerEvent()
{
    qDebug()<<"\nWorker::powerTimerEvent called from: "
       << QThread::currentThreadId();

    if(power_connected())
    {
        qDebug()<<" Read in current voltage input";

        //TODO: replace mock value with actual read() method
        int voltage = m_voltage++;

        if(voltage != m_voltage)
        {
            qDebug()<<" emit voltageChanged";
//            emit voltageChanged(voltage);
        }
        else
        {
            qDebug()<<" no change in voltage";
            // do nothing
        }
    }
    else
    {
        qDebug()<<" Power not connected!";
        // do nothing here
    }

}

void Power::setVoltage(int voltage)
{
    qDebug()<<"\nWorker::setVoltage called from: "
       << QThread::currentThreadId();

    m_voltage = voltage;
    qDebug()<<" m_voltage = "<<voltage;
}


