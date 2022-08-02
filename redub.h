void WatchyBrain::drawRedub(bool light, float batt) {


    // ** SETUP **

      int16_t  x1, y1;
      uint16_t w, h;
      String textstring, texthold;
      
      //drawbg
      display.fillScreen(light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(0, 0, redub_background, 200, 200, light ? GxEPD_WHITE : GxEPD_BLACK);
      
      display.setTextColor(light ? GxEPD_BLACK : GxEPD_WHITE);
      display.setTextWrap(false);

      //draw date
      display.setFont(&Technology18pt7b);
      textstring = dayShortStr(currentTime.Wday);
      textstring.toUpperCase();
      textstring += " ";
      textstring += currentTime.Day;
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(175-w, 90);
      display.print(textstring);

      //draw time
      display.setFont(&Technology40pt7b);

      texthold = currentTime.Hour;
      if (currentTime.Hour < 10) {
        textstring = "0";
      } else {
        textstring = texthold.charAt(0);
      }
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(58-w, 152);
      display.print(textstring);

      if (currentTime.Hour < 10) {
        textstring = texthold.charAt(0);
      } else {
        textstring = texthold.charAt(1);
      }
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(91-w, 152);
      display.print(textstring);

      textstring = ":";
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(100-w/2, 152);
      display.print(textstring);

      texthold = currentTime.Minute; 
      if (currentTime.Minute < 10) {
        textstring = "0";
      } else {
        textstring = texthold.charAt(0);
      }
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(142-w, 152);
      display.print(textstring);

      if (currentTime.Minute < 10) {
        textstring = texthold.charAt(0);
      } else {
        textstring = texthold.charAt(1);
      }
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(175-w, 152);
      display.print(textstring);


      // draw battery
      if (batt > 0) {
       display.fillRect(160,53,15*batt,6,light ? GxEPD_BLACK : GxEPD_WHITE);
      }   

}
