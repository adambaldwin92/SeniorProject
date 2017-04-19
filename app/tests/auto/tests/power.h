#ifndef POWER_H
#define POWER_H


#include <QObject>
#include <QtCore>

class Power : public QObject
{
    Q_OBJECT
public:
    explicit Power(QObject *parent = 0);

    bool power_connected() const { return m_power_connected; }
    int voltage() const { return m_voltage; }

signals:
    void voltageChanged(int voltage);

public slots:
    void connectPower(); //on QThread::started() signal
    void readVoltage(); // on voltageChanged signal
    void updatePower(int voltage);

private:
    bool m_power_connected;
    int m_voltage;

};

#endif // POWER_H
