#ifndef TST_PUMP_H
#define TST_PUMP_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Pump, ConnectPumpTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Pump, ReadFlowrateTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Pump, WriteFlowrateTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}


#endif // TST_PUMP_H