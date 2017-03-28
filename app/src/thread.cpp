#include "thread.h"
#include <QByteArray>
#include <QDataStream>

/*
 * constructor simply stores the socket descriptor and fortune text,
 * so that they are available for run() later on.
 */
Thread::Thread(int socketDescriptor, const int &datum, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor), value(datum)
{
}
/*
 * 1. Create a QTcpSocket object on the stack.
 * 2. The socket is initialized by calling:
 *              QTcpSocket::setSocketDescriptor()
 * 3. Encode the data into a QByteArray using QDataStream.
 * 4. Call QTcpSocket::waitForDisconnected(), which blocks the calling
 *      thread until the socket had disconnected.
 */
void Thread::run()
{
    // 1.
    QTcpSocket tcpSocket;
    // 2.
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());
        return;
    }
    // 3.
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << value;
    // 4.
    tcpSocket.write(block);
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
