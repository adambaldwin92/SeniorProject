#include "camera.h"

Camera::Camera(QObject *parent)
    : QObject(parent),
      m_connected(false)
{
    // connect work signals->slots
//    QObject::connect(this, SIGNAL(camera_connected()), this, SLOT()
    //^^ might not need if using bool flag...
}

void Camera::connectCamera()
{
    qDebug()<<"Camera::connectCamera called from: "
           << QThread::currentThreadId();

    bool success = true; //should actually be return value of connection attempt

    if(success)
    {
        qDebug()<<"Sucessfully connected to Camera\n";
        m_connected = true;
    }
    else // should throw error/exception or wait for connection to establish
    {
        qDebug()<<"ERROR: cannot connect to Camera";
    }

}

void Camera::disconnectCamera()
{
    qDebug()<<"Camera::disconnectCamera called from: "
       << QThread::currentThreadId();

    m_connected = false;
}


//int Camera::readFrame()
//{
//    qDebug()<<"Camera::readFrame called from: "
//       << QThread::currentThreadId();

//    if(connected())
//    {
//        String imageName( "/home/jmdes/Pictures/imagespanda.jpg" );
//        Mat frame;

//        qDebug()<<"Frame input recieved...";

//        frame = imread( imageName, IMREAD_COLOR ); // Read the file
//        emit frameRecieved(frame);
//        return 0;
//    }
//    else
//    {
//        qDebug()<<"Camera not connected!";
//        return -1;
//    }

//}

///* Camera::processFrame()
// *  1. should retrieve consecutive frames from a currently undefined img container
// *  2. employ CV algorithm to determine significant deviations b/w frames
// *  3. significant result from above algorithm should signal for a change in voltage
// *  4. Otherwise do nothing...
// */
//void Camera::processFrame(Mat frame)
//{
//    qDebug()<<"Camera::processFrame called from: "
//       << QThread::currentThreadId();


//    //TODO: replace trivial conditional with actual CV alg

//    bool significantDeviation = true;

//    if(significantDeviation)
//    {
//        qDebug()<<"processFrame has identified deviation";

//        //TODO: call updateVoltage on power thread
//        //with adjusted value determined by CV results
////        int adjustment = 1;
////        updatVoltage(adjustment);
//    }
//    else
//    {
//        qDebug()<<"no deviation in frames";
//        m_frame = frame;
//    }

//}


