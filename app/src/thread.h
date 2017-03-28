#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTcpSocket>


class Thread : public QThread
{
    Q_OBJECT

public:
    Thread(int socketDescriptor, const int &datum, QObject *parent = 0);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    int datum;
};

#endif // THREAD_H
