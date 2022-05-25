#ifndef SIMPBMS_H_
#define SIMPBMS_H_
#include <Arduino.h>
#include "globals.h"
#include <due_can.h>

class SimpBMS : public CANListener //CANListener provides an interface to get callbacks on this class
{
  public:
  void begin(int Port);
  void gotFrame(CAN_FRAME *frame, int mailbox); //overrides the parent version so we can actually do something
  uint8_t getStateOfCharge(); 
  CANRaw *canPort;
  private:
  uint8_t soc;
};
extern SimpBMS simpbms;

#endif
