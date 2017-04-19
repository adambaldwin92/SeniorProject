#include "pump.h"
#include "qdebug.h"

Pump::Pump()
{

}

Pump::~Pump(){}

int Pump::connectPump()
{
    if (WriteComPort("COM4", "A"))
        qDebug() << "Connected to COM port!";
    else
        qDebug() << "Failed to open pump port!";

    return 0;
}

bool Pump::WriteComPort(CString PortSpecifier, CString data)
{
DCB dcb;
 DWORD byteswritten;
 HANDLE hPort = CreateFile(

 PortSpecifier,
 GENERIC_WRITE,
 0,
 NULL,
 OPEN_EXISTING,
 0,
 NULL
 );
 if (!GetCommState(hPort,&dcb))
 return false;
 dcb.BaudRate = CBR_9600; //9600 Baud
 dcb.ByteSize = 8; //8 data bits
 dcb.Parity = NOPARITY; //no parity
 dcb.StopBits = ONESTOPBIT; //1 stop
 if (!SetCommState(hPort,&dcb))
 return false;
 bool retVal = WriteFile(hPort,data,1,&byteswritten,NULL);
 CloseHandle(hPort); //close the handle
 return retVal;
}
