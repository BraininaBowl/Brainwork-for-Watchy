// Global vars
int16_t lineheight = 24;
int16_t curx = 68;
int16_t cury = 12 + lineheight;

void WatchyBrain::drawWrapText(String text){
int16_t  x1, y1, testx, counter;
uint16_t w, h;

  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  testx = curx + w;
  if (testx > 194){
    cury += lineheight; 
    if (cury < 64) {
      curx = 68;
    } else {
      curx = 6;
    }
  }
  display.setCursor(curx,cury);
  curx += w + 5;
  display.print(text);
}

// Text drawing
void WatchyBrain::drawAustenFace(bool light, float batt) {

      int16_t hoffset;
      int16_t arraylength[] = {11,0,20};
      String nmbrs[] = {"midnight", "one", "two", "three", "four", "five", "six", "seven", "eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty-one","twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "half" };
      String pretext[] = {"t", "is", "a", "truth", "universally", "acknowledged,", "that", "a", "single", "man", "at"};
      String text[10] = {};
      if (currentTime.Hour == 12 && currentTime.Minute == 0){
        text[arraylength[1]] = "noon";
        arraylength[1] += 1; 
      } else {
        if (currentTime.Minute == 0){
          hoffset = currentTime.Hour;
        } else if (currentTime.Minute < 31) {
          text[arraylength[1]] = nmbrs[currentTime.Minute];
          arraylength[1] += 1; 
          text[arraylength[1]] = "past";
          arraylength[1] += 1;
          hoffset = currentTime.Hour;
        } else {
          text[arraylength[1]] = nmbrs[60-currentTime.Minute];
          arraylength[1] += 1; 
          text[arraylength[1]] = "to";
          arraylength[1] += 1;           
          hoffset = currentTime.Hour + 1;
        }
        if (hoffset < 13){
          text[arraylength[1]] = nmbrs[hoffset];
          arraylength[1] += 1; 
        } else if (currentTime.Hour == 13) {
          text[arraylength[1]] = "one";
          arraylength[1] += 1; 
        } else {
          text[arraylength[1]] = nmbrs[hoffset-12];
          arraylength[1] += 1; 
        }
        if (currentTime.Minute==0 && currentTime.Hour != 0 && currentTime.Hour != 12) {
          text[arraylength[1]] = "o'clock";
          arraylength[1] += 1;
        }
      }
      
      String posttext[] = {"must", "be", "in", "want", "of", "a", "wife.", "However", "little", "known", "the", "feelings", "or", "views", "of", "such", "a", "man", "may", "be."};
      
      //drawbg
      display.fillScreen(light ? GxEPD_WHITE : GxEPD_BLACK);
      display.drawBitmap(4, 4, Pride, 60, 60, light ? GxEPD_BLACK : GxEPD_WHITE);

      //draw time
      display.setTextColor(light ? GxEPD_BLACK : GxEPD_WHITE);
      display.setTextWrap(false);

      display.setFont(&PTSerif_Regular10pt7b);
      for (int i=0; i<arraylength[0]; i++) {
        drawWrapText(pretext[i]);
      }

      display.setFont(&PTSerif_Bold10pt7b);
      for (int i=0; i<arraylength[1]; i++) {
        drawWrapText(text[i]);
      }

      display.setFont(&PTSerif_Regular10pt7b);
      for (int i=0; i<arraylength[2]; i++) {
        drawWrapText(posttext[i]);
      }


}



// Text drawing
void WatchyBrain::drawPoeFace(bool light, float batt) {

      int16_t hoffset;
      int16_t arraylength[] = {3,0,27};
      String nmbrs[] = {"midnight", "one", "two", "three", "four", "five", "six", "seven", "eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty-one","twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "half" };
      String pretext[] = {"nce", "upon", "a"};
      String text[10] = {};
      if (currentTime.Hour == 12 && currentTime.Minute == 0){
        text[arraylength[1]] = "noon";
        arraylength[1] += 1; 
      } else {
        if (currentTime.Minute == 0){
          hoffset = currentTime.Hour;
        } else if (currentTime.Minute < 31) {
          text[arraylength[1]] = nmbrs[currentTime.Minute];
          arraylength[1] += 1; 
          text[arraylength[1]] = "past";
          arraylength[1] += 1;
          hoffset = currentTime.Hour;
        } else {
          text[arraylength[1]] = nmbrs[60-currentTime.Minute];
          arraylength[1] += 1; 
          text[arraylength[1]] = "to";
          arraylength[1] += 1;           
          hoffset = currentTime.Hour + 1;
        }
        if (hoffset < 13){
          text[arraylength[1]] = nmbrs[hoffset];
          arraylength[1] += 1; 
        } else if (currentTime.Hour == 13) {
          text[arraylength[1]] = "one";
          arraylength[1] += 1; 
        } else {
          text[arraylength[1]] = nmbrs[hoffset-12];
          arraylength[1] += 1; 
        }
        if (currentTime.Minute==0 && currentTime.Hour != 0 && currentTime.Hour != 12) {
          text[arraylength[1]] = "o'clock";
          arraylength[1] += 1;
        }
      }
      
      String posttext[] = {"dreary,", "while", "I", "pondered,", "weak", "and", "weary,", "over", "many", "a", "quaint", "and", "curious", "volume", "of", "forgotten", "lore.", "While", "I", "nodded,", "nearly", "napping,", "suddenly", "there", "came", "a", "tapping"};
      
      //drawbg
      display.fillScreen(light ? GxEPD_WHITE : GxEPD_BLACK);
      display.drawBitmap(4, 4, Raven, 60, 60, light ? GxEPD_BLACK : GxEPD_WHITE);

      //draw time
      display.setTextColor(light ? GxEPD_BLACK : GxEPD_WHITE);
      display.setTextWrap(false);

      display.setFont(&PTSerif_Regular10pt7b);
      for (int i=0; i<arraylength[0]; i++) {
        drawWrapText(pretext[i]);
      }

      display.setFont(&PTSerif_Bold10pt7b);
      for (int i=0; i<arraylength[1]; i++) {
        drawWrapText(text[i]);
      }

      display.setFont(&PTSerif_Regular10pt7b);
      for (int i=0; i<arraylength[2]; i++) {
        drawWrapText(posttext[i]);
      }


}
