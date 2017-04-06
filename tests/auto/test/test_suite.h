#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Test, sample_test)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}





#endif // TEST_SUITE_H
