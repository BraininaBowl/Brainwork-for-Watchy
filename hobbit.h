  void WatchyBrain::drawCentered(String text, int y2) {
    int16_t  x1, y1;
    uint16_t w1, h1;
    
    display.getTextBounds(text, 0, 0, &x1, &y1, &w1, &h1);
    display.setCursor(100-w1/2,y2+h1/2);
    display.print(text);
  }

void WatchyBrain::drawHobbit(int variant, float batt) {


  
  String textstring = "";
  const char *lines [25][3] = {
    {"Midnight","snack"},
    {"Sleep"},
    {"Sleep"},
    {"Sleep"},
    {"Sleep"},
    {"Sleep"},
    {"Almost","breakfast"},
    {"Breakfast"},
    {"Almost","second","breakfast"},
    {"Second","breakfast"},
    {"Almost","elevenses"},
    {"Elevenses"},
    {"Luncheon"},
    {"After","lunch","nap"},
    {"Afternoon","tea"},
    {"Three-ish"},
    {"Almost","dinner"},
    {"Dinner"},
    {"Almost","supper"},
    {"Supper"},
    {"Eight-ish"},
    {"Nine-ish"},
    {"Sleep"},
    {"Sleep"},
    {"Midnight","snack"}
  };
  
  const char linecount[25]= {
    2,
    1,
    1,
    1,
    1,
    1,
    2,
    1,
    3,
    2,
    2,
    1,
    1,
    3,
    2,
    1,
    2,
    1,
    2,
    1,
    1,
    1,
    1,
    1,
    2
  };

  //drawbg
  if (currentTime.Hour < 7 || currentTime.Hour > 20 || currentTime.Hour == 13) {
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
  } else {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
  }

  //drawtime
  display.setFont(&NunitoSans_Black12pt7b);
  textstring = currentTime.Hour;
  textstring += ":";
  if (currentTime.Minute<10){
    textstring += "0";
  }
  textstring += currentTime.Minute;
  drawCentered(textstring,15);

  //drawlabel
  display.setFont(&NunitoSans_Black18pt7b);
  if (linecount[currentTime.Hour] == 1) {
    drawCentered(lines[currentTime.Hour][0],100);
  } else if (linecount[currentTime.Hour] == 2){
    drawCentered(lines[currentTime.Hour][0],82);
    drawCentered(lines[currentTime.Hour][1],118);
  } else if (linecount[currentTime.Hour] == 3) {
    drawCentered(lines[currentTime.Hour][0],64);
    drawCentered(lines[currentTime.Hour][1],100);
    drawCentered(lines[currentTime.Hour][2],136);
  }
}
