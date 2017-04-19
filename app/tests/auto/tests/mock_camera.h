#ifndef MOCK_CAMERA_H
#define MOCK_CAMERA_H

#include "gmock/gmock.h"

using namespace testing;

class Camera {
public:
    virtual ~Camera() {}
    virtual int connectCamera()=0;
};

class MockCamera : public Camera {
public:
    MOCK_METHOD0(connectCamera, int());
};

#endif // MOCK_CAMERA_H
