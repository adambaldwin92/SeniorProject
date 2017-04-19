#ifndef PUMP_H
#define PUMP_H


#include "serial.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdio>
#include <cstring>
#include <cstringt.h>
#include<atlstr.h>

class Pump
{
public:
    Pump();
    ~Pump();
    int connectPump();
    bool WriteComPort(CString PortSpecifier, CString data);

private:
//    CSerial serial;
//    int i, n,
//        cport_nr = 3,   /* /dev/ttyS? (COM4 on windows) */
//        bdrate = 9600;  /* 9600 baud */
//    unsigned char buf[4096];
//    char mode[4]={'8','N','1',(char)0};

};
#endif // PUMP_H
