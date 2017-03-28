#ifndef SERVER_H
#define SERVER_H

#include <QQueue>
#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDesrcriptor) override;

private:
    QQueue<int> data;
};

#endif // SERVER_H
