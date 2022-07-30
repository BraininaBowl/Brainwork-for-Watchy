#ifndef FIRST
  #define FIRST
  // ** INIT **
  bool light = true;
  int face = 0;
#endif

#ifndef MAIN_H
#define MAIN_H

#include <Watchy.h>
#include "brutus_vis.h"
#include "bahn_vis.h"
#include "maze_vis.h"



class WatchyBrain : public Watchy {
  using Watchy::Watchy;
  public:
    void drawWatchFace();
    void drawBrutus(bool light);
    void drawBahn(bool light);
    void drawMaze(bool light);
    virtual void handleButtonPress();//Must be virtual in Watchy.h too
};

#include "brutus.h"
#include "bahn.h"
#include "maze.h"

void WatchyBrain::handleButtonPress() {
  if (guiState == WATCHFACE_STATE) {
    //Up and Down switch watch faces
    uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();
    if (wakeupBit & UP_BTN_MASK) {
      face += 1;
      if (face > 2 ) {face = 0;}
      //Face changed, show immediately
      RTC.read(currentTime);
      showWatchFace(true);
    } else if (wakeupBit & DOWN_BTN_MASK) {
      face -= 1;
      if (face < 0 ) {face = 1;}
      //Face changed, show immediately
      RTC.read(currentTime);
      showWatchFace(true);
    } else if (wakeupBit & BACK_BTN_MASK) {
      light = light ? false : true;
      //Face changed, show immediately
      RTC.read(currentTime);
      showWatchFace(true);
    } else {Watchy::handleButtonPress();}
  } else {Watchy::handleButtonPress();} //Watchy handles menus etc.
}


void WatchyBrain::drawWatchFace() {
  // ** UPDATE **
  //resets step counter at midnight everyday
  if (currentTime.Hour == 00 && currentTime.Minute == 00) {
    sensor.resetStepCounter();
  }
  if (face == 0) {
    drawBrutus(light);  
  } else if (face == 1) {
    drawBahn(light);  
  } else if (face == 1) {
    drawMaze(light);
  }
}

#endif
