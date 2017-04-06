#ifndef GLOBAL_OBJECTS_H
#define GLOBAL_OBJECTS_H



#include "qtimer.h"
#include "qwaitcondition.h"
#include "qmutex.h"

extern QTimer timer;
extern QMutex mutex;
extern QWaitCondition camera_notConnected, power_notConnected;


#endif // GLOBAL_OBJECTS_H
