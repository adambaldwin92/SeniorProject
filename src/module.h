//#ifndef MODULE_H
//#define MODULE_H

//#include <QThread>
//#include <QMutex>
//#include <QWaitCondition>

//class Module : public QThread
//{
//    Q_OBJECT

//public:
//    Module(QObject *parent = 0);
//    ~Module();

//    void transaction(const QString &portName, int waitTimeout, const QString &request);
//    void run();

//signals:
//    void responese(const QString &s);
//    void error(const QString &s);
//    void timeout(const QString &s);

//private:
//    QString portName;
//    QString request;
//    int waitTimeout;
//    QMutex mutex;
//    QWaitCondition cond;
//    bool quit;
//};

//#endif // MODULE_H
