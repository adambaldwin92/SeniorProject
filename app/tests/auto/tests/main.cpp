#include <QCoreApplication>
#include <QApplication>
#include "global_objects.h"
#include"mainwindow.h"
#include "pump.h"
#include"power.h"
#include"camera.h"

QTimer timer;
QThread cam_t, pow_t, pump_t;

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    qDebug()<<"(GUI) main control thread: "<< QThread::currentThreadId();

//    Camera* camera = new Camera();
//    Power* power = new Power();
//    Pump* pump = new Pump();

//    // workerThread.start() will signal-> worker.onStarted()
//    QObject::connect(&cam_t, SIGNAL(started()), camera, SLOT(connectCamera()));
//    QObject::connect(&pow_t, SIGNAL(started()), power, SLOT(connectPower()));
//    QObject::connect(&pump_t, SIGNAL(started()), pump, SLOT(connectPump()));
//    // links each worker with global timer
////  //  QObject::connect(&timer, SIGNAL(timeout()), &camera, SLOT(readFrame()));
////    QObject::connect(&timer, SIGNAL(timeout()), power, SLOT(readVoltage()));

//    // start timer
//    timer.start(1000); //TODO:change to 33ms

//    // move worker objects to their own thread
//    camera->moveToThread(&cam_t);
//    power->moveToThread(&pow_t);
//    pump->moveToThread(&pump_t);

//    // start the worker threads
//    pow_t.start();
//    cam_t.start();
//    pump_t.start();

    return a.exec();
}
