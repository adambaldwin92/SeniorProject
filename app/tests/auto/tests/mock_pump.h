#ifndef MOCK_PUMP_H
#define MOCK_PUMP_H

#include "gmock/gmock.h"

using namespace testing;

class iPump
{
public:
    virtual ~iPump() {}
    virtual int connectPump() = 0;
};

//-------------------------------------------------//

// define mock child of above class
class MockPump : public iPump
{
public:
    MOCK_METHOD0(connectPump, int());
};

//-------------------------------------------------//



#endif // MOCK_PUMP_H
