#ifndef PUMP_H
#define PUMP_H


class Pump
{
private:
//    quint16 PORT;
    double flowrate;
//    QTcpSocket *socket;

public:
    Pump();
    void connectPump();
    double getFlow();
    void readFlowrate();
    void writeFlowrate(double f);
    ~Pump();
};


#endif // PUMP_H
