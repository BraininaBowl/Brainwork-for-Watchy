void WatchyBrain::drawBrutus(bool light, float batt) {
  const unsigned char *numbers_large [10] = {brutuslarge_0,brutuslarge_1,brutuslarge_2,brutuslarge_3,brutuslarge_4,brutuslarge_5,brutuslarge_6,brutuslarge_7,brutuslarge_8,brutuslarge_9};
  const unsigned char *numbers_small [10] = {brutussmall_0,brutussmall_1,brutussmall_2,brutussmall_3,brutussmall_4,brutussmall_5,brutussmall_6,brutussmall_7,brutussmall_8,brutussmall_9};
  const uint16_t color = light ? GxEPD_WHITE : GxEPD_BLACK;
  const uint16_t opposite_color  = light ? GxEPD_BLACK : GxEPD_WHITE;

      // drawbg
      display.fillScreen(color);

      // draw time

      display.drawBitmap(0, 0, numbers_large[currentTime.Hour/10], 98, 90, color, opposite_color); //pass in second color for background color, bypassing need for fillrect.
      display.drawBitmap(102, 0, numbers_large[currentTime.Hour%10], 98, 90, color, opposite_color);
      display.drawBitmap(0, 94, numbers_large[currentTime.Minute/10], 98, 90, color, opposite_color);
      display.drawBitmap(102, 94, numbers_large[currentTime.Minute%10], 98, 90, color, opposite_color);
     
      // draw date
      display.drawBitmap(0, 188, brutuscal, 6, 12, color, opposite_color);
      display.drawBitmap(10, 188, numbers_small[currentTime.Day/10], 6, 12, color, opposite_color);
      display.drawBitmap(18, 188, numbers_small[currentTime.Day%10], 6, 12, color, opposite_color);
      display.drawBitmap(30, 188, numbers_small[currentTime.Month/10], 6, 12, color, opposite_color);
      display.drawBitmap(38, 188, numbers_small[currentTime.Month%10], 6, 12, color, opposite_color);

      // draw steps
      int textstring = sensor.getCounter();
      display.drawBitmap(194, 188, numbers_small[textstring%10], 6, 12, color, opposite_color);
      display.drawBitmap(186, 188, numbers_small[textstring/10%10], 6, 12, color, opposite_color); //this can address way outside bounds (eg index 99 at 990 steps) without %10
      display.drawBitmap(178, 188, numbers_small[textstring/100%10], 6, 12, color, opposite_color);
      display.drawBitmap(170, 188, numbers_small[textstring/1000%10], 6, 12, color, opposite_color);
      display.drawBitmap(162, 188, numbers_small[textstring/10000%10], 6, 12, color, opposite_color);
      display.drawBitmap(154, 188, numbers_small[textstring/100000%10], 6, 12, color, opposite_color);
      display.drawBitmap(146, 188, numbers_small[textstring/1000000%10], 6, 12, color, opposite_color);
      display.drawBitmap(136, 188, brutusstep, 6, 12, color);

      // draw battery
      display.fillRect(48,188,84,8,color);
      display.fillRect(48,198,84*batt,2,color);
}
