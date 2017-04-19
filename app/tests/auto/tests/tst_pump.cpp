#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../../app/src/pump.h"

//using namespace testing;

//TEST(PumpTest, SampleTest)
//{
//    EXPECT_EQ(1, 1);
//    ASSERT_THAT(0, Eq(0));

//    Pump pump;
//    EXPECT_EQ(0, pump.Bar());
//}

namespace {

// The fixture for testing class Foo.
class PumpTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  PumpTest() {
    // You can do set-up work for each test here.
  }

  virtual ~PumpTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  Pump pump;
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(PumpTest, MethodBarDoesAbc) {
//    pump = new Pump();
//  EXPECT_EQ(0, pump.Bar());
    EXPECT_EQ(0, 0);
}

// Tests that Foo does Xyz.
TEST_F(PumpTest, DoesXyz) {
  // Exercises the Xyz feature of Foo.
}

}  // namespace

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

