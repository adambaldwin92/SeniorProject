#ifndef MOCKS_H
#define MOCKS_H

#include"interfaces.h"
#include<gmock/gmock.h>

class MockPump : public iPump {
 public:
  MOCK_METHOD0(connectPump,
      int());
  MOCK_METHOD0(startPump,
      int());
  MOCK_METHOD0(stopPump,
      int());
  MOCK_METHOD1(setRate,
      int(double flowrate));
};

class MockPower : public iPower {
 public:
  MOCK_METHOD0(connectPower,
      int());
  MOCK_METHOD1(writeVoltage,
      int(double voltage));
  MOCK_METHOD0(readVoltage,
      int());
};

class MockCamera : public iCamera {
 public:
  MOCK_METHOD0(connectCamera,
      int());
};

#endif // MOCKS_H
