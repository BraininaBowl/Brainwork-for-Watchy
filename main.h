#ifndef MAIN_H
#define MAIN_H

#include <Watchy.h>
#include "brain_vis.h"

RTC_DATA_ATTR int face = 0;
RTC_DATA_ATTR int faces_vars[5][2] = {{1,0},{1,0},{1,0},{1,0},{2,0}}; //variants, current
//Brutus, Bahn, Maze, Redub, Novel

class WatchyBrain : public Watchy {
  using Watchy::Watchy;
  public:
    void drawWatchFace();
    void drawWrapText(String text);
    void drawBrutus(int variant, float batt);
    void drawBahn(int variant, float batt);
    void drawMaze(int variant, float batt);
    void drawRedub(int variant, float batt);
    void drawNovel(int variant, float batt);
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
      if (face < 0 ) { face = 4; }
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    }
    if (wakeupBit & DOWN_BTN_MASK) {
      face++;
      if (face > 4 ) { face = 0; }
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    }
    if (wakeupBit & BACK_BTN_MASK) {
      faces_vars[face][1]++;
      if (faces_vars[face][1] > faces_vars[face][0]){faces_vars[face][1] = 0;}
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
    drawBrutus(faces_vars[face][1], batt);
  }
  if (face == 1) {
    drawBahn(faces_vars[face][1], batt);  
  }
  if (face == 2) {
    drawMaze(faces_vars[face][1], batt);
  }
  if (face == 3) {
    drawRedub(faces_vars[face][1], batt);
  }
  if (face == 4) {
    drawNovel(faces_vars[face][1], batt);
  }
}

#endif
