#ifndef FOOTEST_H
#define FOOTEST_H


class FooTest : public ::testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

#endif // FOOTEST_H
