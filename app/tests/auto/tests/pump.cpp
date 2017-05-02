
#include "pump.h"
#include <qdebug.h>

Pump::Pump()
    : m_connected(false),
      m_flowrate(0)
{
}

int Pump::connectPump()
{
// <--check out "plink" in PuTTY--->
    qDebug() << "connectPump called...";

    arguments << "-serial" << "com4"
                 ;
    putty = new QProcess(this);
    putty->start(program, arguments);
    if (!putty->waitForStarted())
        return false;
//    putty->write(help);
    putty->write("help");

    QByteArray result = putty->readAll();

    qDebug() << result;

    startPump();
    putty->closeWriteChannel();
//    system(WshShell.Run( "putty.exe"));

//    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 -m "+startCmd);

    return 0;
}


int Pump::startPump()
{

    putty->write(help);
    putty->write(start);
    putty->write(help);
//    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 \"start\"");
    return 0;
}

int Pump::stopPump()
{
//    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 \"stop\"");
    return 0;
}

int Pump::setRate(double flowrate)
{
//    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4 \"set rate "+flowrate+"\"");
    return 0;
}
