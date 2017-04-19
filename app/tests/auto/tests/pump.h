#ifndef PUMP_H
#define PUMP_H


//#include "serial.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include<atlstr.h>
#include "rs232.h"
using namespace std;


class Pump
{
public:
    Pump();
    ~Pump();
    int connectPump();


private:


};
#endif // PUMP_H
