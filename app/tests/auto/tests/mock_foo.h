#ifndef MOCK_FOO_H
#define MOCK_FOO_H

#include "gmock/gmock.h"

using namespace testing;

// define virtual class (interface)
class Foo
{
public:
    virtual ~Foo() {}
    virtual int bar() = 0;
};

class MyFoo : public Foo
{
public:
    int bar() { return 0; }
};

// define mock child of above class
class MockFoo : public Foo
{
public:
    MOCK_METHOD0(bar, int());
};

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  FooTest() {
    // You can do set-up work for each test here.
  }

  virtual ~FooTest() {
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
};





//TEST(FooTest, SampleMockTest)
//{
//    MockFoo foo;
//    EXPECT_CALL(foo, bar())
//            .Times(AtLeast(1))
//            .WillOnce( Return(0) );

//    EXPECT_EQ(0, foo.bar());

////    EXPECT_EQ(1, 0);
////    ASSERT_THAT('a', Eq(0));
////    EXPECT_EQ(1, 1);
////    ASSERT_THAT(0, Eq(0));


//}





#endif // MOCK_FOO_H
