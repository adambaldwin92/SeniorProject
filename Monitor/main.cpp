//#include "mainwindow.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include "worker.h"
#include"camera.h"
#include"power.h"
#include "global_objects.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    qDebug()<<"(GUI) main control thread: "<< QThread::currentThreadId();

    // declare worker objects and threads
    Camera camera;
    Power power;
    QThread cam_t, pow_t;

    // workerThread.start() will signal-> worker.onStarted()
    QObject::connect(&cam_t, SIGNAL(started()), &camera, SLOT(connectCamera()));
    QObject::connect(&pow_t, SIGNAL(started()), &power, SLOT(connectPower()));

    // links each worker with global timer
    QObject::connect(&timer, SIGNAL(timeout()), &camera, SLOT(cameraTimerEvent()));
    QObject::connect(&timer, SIGNAL(timeout()), &power, SLOT(powerTimerEvent()));

    QObject::connect(&power,SIGNAL(voltageChanged(int)),&power,SLOT(setVoltage(int)));

    // start timer
    timer.start(1000);

    // move worker objects to their own thread
    camera.moveToThread(&cam_t);
    power.moveToThread(&pow_t);

    // start the worker threads
    cam_t.start();
    pow_t.start();


    return a.exec();
//    return app.exec();
}
