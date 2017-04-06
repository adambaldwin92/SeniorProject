#include "camera.h"

Camera::Camera(QObject *parent)
    : QObject(parent),
      m_camera_connected(false)
{
    QObject::connect(this,SIGNAL(frameRecieved(int)),this,SLOT(processFrame(int)));
}

void Camera::connectCamera()
{
    qDebug()<<"\nCamera::connectCamera called from: "
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

void Camera::cameraTimerEvent()
{
    qDebug()<<"\nCamera::cameraTimerEvent called from: "
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

/* Worker::processFrame()
 *  1. should retrieve consecutive frames from a currently undefined img container
 *  2. employ CV algorithm to determine significant deviations b/w frames
 *  3. significant result from above algorithm should signal for a change in voltage
 *  4. Otherwise do nothing...
 */
void Camera::processFrame()
{
    qDebug()<<"\nWorker::processFrame called from: "
       << QThread::currentThreadId();

    //TODO: replace trivial conditional with actual CV alg
    bool significantDeviation = true;

    if(significantDeviation)
    {
        qDebug()<<" Deviation identified";

        //TODO: replace mock decrement with adjusted value determined by CV results
//        m_voltage--; // TODO: replace this with setVoltage();
    }
    else
    {
        qDebug()<<" No deviation identified";
    }

}
