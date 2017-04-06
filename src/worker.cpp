#include "worker.h"
// global variables
QWaitCondition camera_notConnected;
QWaitCondition power_notConnected;
QMutex mutex;
QTimer timer;

Worker::Worker(QObject *parent)
    : QObject(parent),
      m_camera_connected(false),
      m_power_connected(false)
{
    QObject::connect(this,SIGNAL(voltageChanged(int)),this,SLOT(setVoltage(int)));
    QObject::connect(this,SIGNAL(frameRecieved(int)),this,SLOT(processFrame(int)));
}

void Worker::connectCamera()
{
    qDebug()<<"\nWorker::connectCamera called from: "
           << QThread::currentThreadId();

    bool success = true; //should actually be return value of connection attempt

    if(success)
    {
        qDebug()<<" Sucessfully connected to Camera\n";
        m_camera_connected = true;
    }
    else // should throw error/exception or wait for connection to establish
    {
        qDebug()<<"     ERROR: cannot connect to Camera";
    }

}

void Worker::connectPower()
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

void Worker::cameraTimerEvent()
{
    qDebug()<<"\nWorker::cameraTimerEvent called from: "
       << QThread::currentThreadId();

    if(camera_connected())
    {
        qDebug()<<" Frame input recieved...";
        int frame = 0; // TODO: this is tmp value to represent inputed frame
        emit frameRecieved(frame);
    }
    else
    {
        qDebug()<<" ERROR: Camera not connected!";
    }

}


/*
 * Worker::changeVoltage may need mutex so
 * voltage value doesnt become corrupt
 */
void Worker::powerTimerEvent()
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
            emit voltageChanged(voltage);
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


/* Worker::processFrame()
 *  1. should retrieve consecutive frames from a currently undefined img container
 *  2. employ CV algorithm to determine significant deviations b/w frames
 *  3. significant result from above algorithm should signal for a change in voltage
 *  4. Otherwise do nothing...
 */
void Worker::processFrame()
{
    qDebug()<<"\nWorker::processFrame called from: "
       << QThread::currentThreadId();

    //TODO: replace trivial conditional with actual CV alg
    bool significantDeviation = true;

    if(significantDeviation)
    {
        qDebug()<<" Deviation identified";

        //TODO: replace mock decrement with adjusted value determined by CV results
        m_voltage--;
    }
    else
    {
        qDebug()<<" No deviation identified";
    }

}

void Worker::setVoltage(int voltage)
{
    qDebug()<<"\nWorker::setVoltage called from: "
       << QThread::currentThreadId();

    m_voltage = voltage;
    qDebug()<<" m_voltage = "<<voltage;
}
