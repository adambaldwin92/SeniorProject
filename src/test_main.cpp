#include <gtest/gtest.h>
#include"camera_test.h"
#include"power_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
