#ifndef POWER_H
#define POWER_H

#include"interfaces.h"
//#include <QObject>
//#include <QtCore>

class Power : public iPower
{
//    Q_OBJECT
public:
//    explicit Power(iPower const *parent = 0);
    Power();

    bool power_connected() const { return m_power_connected; }
    int voltage() const { return m_voltage; }

//signals:
//    void voltageChanged(int voltage);

public slots:
    int connectPower(); //on QThread::started() signal
    int readVoltage(); // on voltageChanged signal
    int writeVoltage(double voltage);

private:
    bool m_power_connected;
    int m_voltage;

};

#endif // POWER_H
