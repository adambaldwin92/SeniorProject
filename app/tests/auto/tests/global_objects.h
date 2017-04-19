#ifndef GLOBAL_OBJECTS_H
#define GLOBAL_OBJECTS_H


#include "qtimer.h"
#include "qthread.h"
#include "qmutex.h"
#include "camera.h"
#include "power.h"

extern QTimer timer;
extern QMutex mutex;
extern Camera camera;
extern Power power;
extern QThread cam_t, pow_t;


#endif // GLOBAL_OBJECTS_H
