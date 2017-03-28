#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTcpSocket>


class Thread : public QThread
{
    Q_OBJECT

public:
    Thread(int socketDescriptor, const int &datum, QObject *parent);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    int value;
};

#endif // THREAD_H
