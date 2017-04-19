#include "pump.h"
#include "qdebug.h"

Pump::Pump()
{

}

Pump::~Pump(){}

int Pump::connectPump()
{
    system("\"C:\\Program Files\\PuTTY\\putty.exe\" -serial com4");

    return 0;
}


