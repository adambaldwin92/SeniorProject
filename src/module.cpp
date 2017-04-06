//#include "module.h"

//#include <QtSerialPort/QSerialPort>

//#include <QTime>

//QT_USE_NAMESPACE

//Module::Module(QObject *parent)
//    : QThread(parent), waitTime(0), quit(false)
//{
//}

//Module::~Module()
//{
//    mutex.lock();
//    quit = true;
//    cond.wakeOne();
//    mutex.unlock();
//    wait();
//}

//void Module::transaction(const QString &portName, int waitTimeout, const QString &request)
//{
//    //! [1]
//    QMutexLocker locker(&mutex);
//    this->portName = portName;
//    this->waitTimeout = waitTimeout;
//    this->request = request;
//    //! [3]
//    if (!isRunning())
//        start();
//    else
//        cond.wakeOne();
//}

//void Module::run()
//{

//    QSerialPort serial;
//    serial.setPortName(portName);

//    if (!serial.open(QIODevice::ReadWrite)) {
//        emit error(tr("Can't open %1, error code %2")
//                   .arg(portName).arg(serial.error()));
//        return;
//    }





//}
