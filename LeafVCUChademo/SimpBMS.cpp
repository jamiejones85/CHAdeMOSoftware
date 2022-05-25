#include "SimpBMS.h"

void SimpBMS::begin(int port) {
  if (port == 0)
  {
    canPort = &Can0;
  }
  else
  {
      canPort = &Can1;
  }
  canPort->attachObj(this);
  attachMBHandler(0);
}

//Add handling of over voltage and temperature
void SimpBMS::gotFrame(CAN_FRAME* frame, int mailbox) {
    switch (frame->id) {
     case 0x355:
      soc = (frame->data.byte[1] << 8) + frame->data.byte[0];
     break;
    }
}

uint8_t SimpBMS::getStateOfCharge() {
  return soc;
}

SimpBMS simpbms;
