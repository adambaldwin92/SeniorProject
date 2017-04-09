#include <QCoreApplication>
#include "global_objects.h"

QTimer timer;
Camera camera;
Power power;
QThread cam_t, pow_t;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"(GUI) main control thread: "<< QThread::currentThreadId();

    // workerThread.start() will signal-> worker.onStarted()
    QObject::connect(&cam_t, SIGNAL(started()), &camera, SLOT(connectCamera()));
    QObject::connect(&pow_t, SIGNAL(started()), &power, SLOT(connectPower()));

    // links each worker with global timer
    QObject::connect(&timer, SIGNAL(timeout()), &camera, SLOT(readFrame()));
    QObject::connect(&timer, SIGNAL(timeout()), &power, SLOT(readVoltage()));

    // start timer
    timer.start(31);

    // move worker objects to their own thread
    camera.moveToThread(&cam_t);
    power.moveToThread(&pow_t);

    // start the worker threads
    cam_t.start();
    pow_t.start();

    return a.exec();
}
