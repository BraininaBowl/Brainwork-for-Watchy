#ifndef FIRST
  #define FIRST
  // ** INIT **
  bool light = true;
  int face = 0;
#endif

#ifndef MAIN_H
#define MAIN_H

#include <Watchy.h>
#include "bahn_vis.h"
#include "maze_vis.h"



class WatchyBrain : public Watchy {
  using Watchy::Watchy;
  public:
    void drawWatchFace();
    void drawBahn(bool light);
    void drawMaze(bool light);
    virtual void handleButtonPress();//Must be virtual in Watchy.h too
};

#include "bahn.h"
#include "maze.h"

void WatchyBrain::handleButtonPress() {
  if (guiState == WATCHFACE_STATE) {
    //Up and Down switch watch faces
    uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();
    if (wakeupBit & UP_BTN_MASK) {
      face += 1;
    } else if (wakeupBit & DOWN_BTN_MASK) {
      face -= 1;
    } else if (wakeupBit & BACK_BTN_MASK) {
      if (light == false) {
        light = true;
        //display.epd2.setDarkBorder(false);
      } else {
        light = false;
        //display.epd2.setDarkBorder(true);
      }
    }
    if (face < 0 ) {face = 1;}
    if (face > 1 ) {face = 0;}
    if (wakeupBit & (DOWN_BTN_MASK | UP_BTN_MASK | BACK_BTN_MASK)) {
      //Face changed, show immediately
      RTC.read(currentTime);
      showWatchFace(true);
      Watchy::handleButtonPress();
    }
    else Watchy::handleButtonPress();
  } else Watchy::handleButtonPress(); //Watchy handles menus etc.
}


void WatchyBrain::drawWatchFace() {



  // ** UPDATE **
  //resets step counter at midnight everyday
  if (currentTime.Hour == 00 && currentTime.Minute == 00) {
    sensor.resetStepCounter();
  }
  if (face == 0) {
    drawBahn(light);  
  } else {
    drawMaze(light);
  }
  
}

#endif
