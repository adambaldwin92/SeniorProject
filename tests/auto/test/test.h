#ifndef TEST_H
#define TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "interfaces.h"

using namespace testing;

TEST(Test, sample_test)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(Power, read_volt_input)
{
    Power *power = new Power();
    ASSERT_EQ(power->readVolt(), 0);
}


#endif // TEST_H
