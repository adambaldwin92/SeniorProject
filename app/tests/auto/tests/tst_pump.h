#ifndef TST_PUMP_H
#define TST_PUMP_H

#include"pump.h"
#include "mocks.h"
using namespace testing;

TEST(MockPump, CommPortConnectionReturnsZero) {
    MockPump pump;
    EXPECT_CALL(pump, connectPump())
            .Times(AtLeast(1))
            .WillOnce( Return(0) );
    EXPECT_EQ(0, pump.connectPump());
}
TEST(MockPump, StartPumpReturnsZeroWhenPumpStopped)
{
    MockPump pump;
    EXPECT_CALL(pump, startPump())
            .Times(AtLeast(1))
            .WillOnce( Return(0) );
    EXPECT_EQ(0, pump.startPump());
}
TEST(MockPump, StopPumpReturnsZeroWhenPumpStarted)
{
    MockPump pump;
    EXPECT_CALL(pump, stopPump())
            .Times(AtLeast(1))
            .WillOnce( Return(0) );
    EXPECT_EQ(0, pump.stopPump());
}
TEST(MockPump, SetRateReturnsZeroForValidArg)
{
    MockPump pump;
    EXPECT_CALL(pump, setRate(1.0))
            .Times(2)
            .WillRepeatedly( Return(0) );
    EXPECT_EQ(0, pump.setRate(1.0));
    ASSERT_EQ(0, pump.setRate(1.0));
}
TEST(MockPump, SetRateReturnsNegOneForInvalidArg)
{
    MockPump pump;
    EXPECT_CALL(pump, setRate(100.0))
            .Times(2)
            .WillRepeatedly( Return(-1) );
    EXPECT_EQ(-1, pump.setRate(100.0));
    ASSERT_EQ(-1, pump.setRate(100.0));
}
//// The fixture for testing class Foo.
//class PumpTest : public ::testing::Test {
// protected:
//    PumpTest() {}
//    virtual ~PumpTest() {}
//    virtual void SetUp() {}
//    virtual void TearDown() {}

//  // Objects declared here can be used by all tests in the test case for Foo.

//};

//// Tests that the Foo::bar() method returns 0.
//TEST_F(PumpTest, ConnectPumpReturnsZero) {
//    Pump p;
//    EXPECT_EQ(0, p.connectPump());
//}

#endif // TST_PUMP_H
