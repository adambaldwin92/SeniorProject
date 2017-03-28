#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include <QString>
#include <QNetworkSession>
#include <QtWidgets/QDialog>

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = Q_NULLPTR);

private slots:
    /* TODO: the below (virtual?) methods are experiencing
     *  issue: LNK2019: unresolved external symbol
     */
//    void requestNewData();
//    void readData();
//    void displayError(QAbstractSocket::SocketError socketError);
//    void sessionOpened();

private:
    QTcpSocket *tcpSocket;
    QDataStream in;
    QString currentValue;

    QNetworkSession *networkSession;
};

#endif // CLIENT_H