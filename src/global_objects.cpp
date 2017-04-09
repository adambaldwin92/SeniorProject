#include "global_objects.h"

namespace
{
    QTimer timer;
    QMutex mutex;
    Camera camera;
    Power power;
    QThread cam_t, pow_t;
}
