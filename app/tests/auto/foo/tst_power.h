#ifndef TST_POWER_H
#define TST_POWER_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;


//class PowerTest : public Test {
//protected:
//    virtual void SetUp() {

//    }
//};

TEST(Power, ConnectPowerTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Power, ReadVoltageTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Power, WriteVoltageTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}




#endif // TST_POWER_H
