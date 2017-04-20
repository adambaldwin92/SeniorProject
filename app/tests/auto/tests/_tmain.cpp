#include "tst_pump.h"
#include"tst_camera.h"
#include "tst_power.h"
//#include"tst_foo.h"


#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
