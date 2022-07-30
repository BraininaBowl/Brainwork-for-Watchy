void WatchyBrain::drawBrutus(bool light) {
  const unsigned char *numbers_large [10] = {brutuslarge_0,brutuslarge_1,brutuslarge_2,brutuslarge_3,brutuslarge_4,brutuslarge_5,brutuslarge_6,brutuslarge_7,brutuslarge_8,brutuslarge_9};
  const unsigned char *numbers_small [10] = {brutussmall_0,brutussmall_1,brutussmall_2,brutussmall_3,brutussmall_4,brutussmall_5,brutussmall_6,brutussmall_7,brutussmall_8,brutussmall_9};
            
      //drawbg
      display.fillScreen(light ? GxEPD_WHITE : GxEPD_BLACK);

      //draw time
      display.fillRect(0,0,98,90, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(0, 0, numbers_large[currentTime.Hour/10], 98, 90, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(102,0,98,90, light ? GxEPD_BLACK : GxEPD_WHITE);  
      display.drawBitmap(102, 0, numbers_large[currentTime.Hour%10], 98, 90, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(0,94,98,90, light ? GxEPD_BLACK : GxEPD_WHITE);  
      display.drawBitmap(0, 94, numbers_large[currentTime.Minute/10], 98, 90, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(102,94,98,90, light ? GxEPD_BLACK : GxEPD_WHITE); 
      display.drawBitmap(102, 94, numbers_large[currentTime.Minute%10], 98, 90, light ? GxEPD_WHITE : GxEPD_BLACK);
     
      // draw date
      display.fillRect(0,188,6,12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(0, 188, brutuscal, 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(10,188,6,12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(10, 188, numbers_small[currentTime.Day/10], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(18,188,6,12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(18, 188, numbers_small[currentTime.Day%10], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(30,188,6,12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(30, 188, numbers_small[currentTime.Month/10], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(38,188,6,12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(38, 188, numbers_small[currentTime.Month%10], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);





      // draw steps
      int textstring = sensor.getCounter();
      display.fillRect(194, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(194, 188, numbers_small[textstring%10], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(186, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(186, 188, numbers_small[textstring/10], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(178, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(178, 188, numbers_small[textstring/100], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(170, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(170, 188, numbers_small[textstring/1000], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(162, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(162, 188, numbers_small[textstring/10000], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(154, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(154, 188, numbers_small[textstring/100000], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(146, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(146, 188, numbers_small[textstring/1000000], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(138, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(138, 188, numbers_small[textstring/10000000], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(130, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(130, 188, numbers_small[textstring/100000000], 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(120, 188, 6, 12, light ? GxEPD_BLACK : GxEPD_WHITE);
      display.drawBitmap(120, 188, brutusstep, 6, 12, light ? GxEPD_WHITE : GxEPD_BLACK);
}
