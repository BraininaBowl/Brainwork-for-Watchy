#ifndef MAIN_H
#define MAIN_H

#include <Watchy.h>
#include "brutus_vis.h"
#include "bahn_vis.h"
#include "maze_vis.h"
#include "redub_vis.h"
#include "novel_vis.h"

RTC_DATA_ATTR bool light = true;
RTC_DATA_ATTR int face = 0;


class WatchyBrain : public Watchy {
  using Watchy::Watchy;
  public:
    void drawWatchFace();
    void drawWrapText(String text);
    void drawBrutus(bool light, float batt);
    void drawBahn(bool light, float batt);
    void drawMaze(bool light, float batt);
    void drawRedub(bool light, float batt);
    void drawAustenFace(bool light, float batt);
    void drawPoeFace(bool light, float batt);
    virtual void handleButtonPress();//Must be virtual in Watchy.h too
};

#include "brutus.h"
#include "bahn.h"
#include "maze.h"
#include "redub.h"
#include "novel.h"

void WatchyBrain::handleButtonPress() {
  if (guiState == WATCHFACE_STATE) {
    //Up and Down switch watch faces
    uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();
    if (wakeupBit & UP_BTN_MASK) {
      face--;
      if (face < 0 ) { face = 5; }
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    }
    if (wakeupBit & DOWN_BTN_MASK) {
      face++;
      if (face > 5 ) { face = 0; }
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    }
    if (wakeupBit & BACK_BTN_MASK) {
      light = !light;
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    } 
    if (wakeupBit & MENU_BTN_MASK) {
      Watchy::handleButtonPress();
      return;
    }
  } else {Watchy::handleButtonPress();}
  return;
}


void WatchyBrain::drawWatchFace() {
  // ** UPDATE **
  //resets step counter at midnight everyday
  if (currentTime.Hour == 00 && currentTime.Minute == 00) {
    sensor.resetStepCounter();
  }

  // ** GET BATTERY **
  float batt = (getBatteryVoltage()-3.3);
  if (batt > 1) { batt = 1; } else if (batt < 0) { batt = 0; }
  
  // ** DRAW WATCHFACE **
  if (face == 0) {
    drawBrutus(light, batt);
  }
  if (face == 1) {
    drawBahn(light, batt);  
  }
  if (face == 2) {
    drawMaze(light, batt);
  }
  if (face == 3) {
    drawRedub(light, batt);
  }
  if (face == 4) {
    drawPoeFace(light, batt);
  }
  if (face == 5) {
    drawAustenFace(light, batt);
  }
}

#endif
