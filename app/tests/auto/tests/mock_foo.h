#ifndef MOCK_FOO_H
#define MOCK_FOO_H

#include "gmock/gmock.h"

using namespace testing;

// define virtual class (interface)
class iFoo
{
public:
    virtual ~iFoo() {}
    virtual int bar() = 0;
};

class Foo : public iFoo
{
public:
    int bar() { return 0; }
};

// define mock child of above class
class MockFoo : public iFoo
{
public:
    MOCK_METHOD0(bar, int());
};



#endif // MOCK_FOO_H
