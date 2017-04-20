#ifndef TST_PUMP_H
#define TST_PUMP_H

#include"pump.h"
#include "mocks.h"

// The fixture for testing class Foo.
class PumpTest : public ::testing::Test {
 protected:
    PumpTest() {}
    virtual ~PumpTest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}

  // Objects declared here can be used by all tests in the test case for Foo.

};

// Tests that the Foo::bar() method returns 0.
TEST_F(PumpTest, ConnectPumpReturnsZero) {
    Pump p;
    EXPECT_EQ(0, p.connectPump());
}

#endif // TST_PUMP_H
