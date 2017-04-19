#ifndef TST_FOO_H
#define TST_FOO_H

#include"mock_foo.h"

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
 protected:
    FooTest() {}
    virtual ~FooTest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}

  // Objects declared here can be used by all tests in the test case for Foo.

};

// Tests that the Foo::bar() method returns 0.
TEST_F(FooTest, MethodBarReturnsZero) {
    Foo f;
    EXPECT_EQ(0, f.bar());
}

TEST(MockFoo, MockBarReturnsZero) {
//  Foo f;
//  EXPECT_EQ(0, f.bar());

    MockFoo foo;
    EXPECT_CALL(foo, bar())
            .Times(AtLeast(1))
            .WillOnce( Return(0) );

    EXPECT_EQ(0, foo.bar());
}


#endif // TST_FOO_H
