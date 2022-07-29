
#ifndef BAHN_H
#define BAHN_H

#include <Watchy.h>
#include "DIN_1451_Engschrift_Regular64pt7b.h"
#include "DIN_1451_Engschrift_Regular12pt7b.h"



class WatchyBrain : public Watchy {
  using Watchy::Watchy;
  public:
    // ** INIT **
    bool light = true;
    void drawWatchFace();
    void drawBahn(bool light);
};

#include "bahn.h"

void WatchyBrain::drawWatchFace() {



  // ** UPDATE **
  //resets step counter at midnight everyday
  if (currentTime.Hour == 00 && currentTime.Minute == 00) {
    sensor.resetStepCounter();
  }

  drawBahn(light);
}

#endif
