#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
Adafruit_SSD1306 display(-1);

// G L O B A L S
int state = 0;
int mainMenuItem = 1;
int mainMenuPage = 1;
int upBtn = 6;
int downBtn = 7;
int leftBtn = 5;
int rightBtn = 8;
int aBtn = 9;
int bBtn = 10;

// S E T U P
void setup() {                
	// initialize with the I2C addr 0x3C
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // load main menu
  mainMenu(0, 1);
}

// 
void goBackToMainMenu(int page, int item) {
  state = 0;
  mainMenuPage = 1;
  mainMenuItem = 1;
}

// M A I N  M E N U
bool isItemWhite1 = true;
bool isItemWhite2 = true;
void mainMenu(int page, int item) {
  // Clear Screen
	display.clearDisplay();

  // Light
  if(page == 1){
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  } 
  if(page == 2){
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  } 

  // Title
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(36, 0);
  display.println("Main Menu");  

  // Options
  if(item == 1){
    isItemWhite1 = false;
    isItemWhite2 = true;
    display.fillRoundRect(10, 10, 50, 20, 100, WHITE);
    display.drawRect(70, 10, 50, 20, WHITE);
  } else {
    isItemWhite1 = true;
    isItemWhite2 = false;
    display.drawRect(10, 10, 50, 20, WHITE);
    display.fillRoundRect(70, 10, 50, 20, 100, WHITE);
  }

  // Page 1
  if(page == 1){
    if(isItemWhite1){
      display.setTextColor(WHITE);
    } else {
      display.setTextColor(BLACK);
    }
    display.setCursor(22, 17);
    display.print("APPS");
    if(isItemWhite2){
      display.setTextColor(WHITE);
    } else {
      display.setTextColor(BLACK);
    }
    display.setCursor(80, 17);
    display.print("GAMES");
  }

  if(page == 2){
    if(isItemWhite1){
      display.setTextColor(WHITE);
    } else {
      display.setTextColor(BLACK);
    }
    display.setCursor(22, 17);
    display.print("EXTRA");
    if(isItemWhite2){
      display.setTextColor(WHITE);
    } else {
      display.setTextColor(BLACK);
    }
    display.setCursor(81, 17);
    display.print("INFO");
  }

  // Display
  display.display();
}

// I N F O  P A G E
int infoPageX = 5;
int infoPageY = 12;
int infoNameFlash = true;
void infoPage() {
  // Clear Display
  display.clearDisplay();

  // Title
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, infoPageY - 9);
  display.println("   Info              ");

  // Info
  display.setTextColor(WHITE);
  display.setCursor(infoPageX, infoPageY);
  display.println("This is a custom gaming console made by Dagmawi Babi running on an Arduino Nano.");

  // Specs
  display.setTextColor(BLACK, WHITE);
  display.println("\n   Specs            ");  
  display.setTextColor(WHITE);
  display.println("Microcontroller \n    - ATmega328");
  display.println("Operating Voltage \n    - 5V");
  display.println("Flash Memory - 32 KB");  
  display.println("Clock Speed - 16 MHz");  
  display.println("SRAM - 2 KB");  
  display.println("EEPROM - 1 KB");  
  display.println("Resolution	\n    - 128 X 64 px");
  display.println("Screen Size - 0.96 in");  
  display.println("View Angle - 160 deg");  

  // Version
  display.setTextColor(BLACK, WHITE);
  display.println("\n   Owner            ");  
  display.setTextColor(WHITE);
  display.println(" Dagmawi Babi");
  display.println(" Dream Intelligence");

  // Date
  display.setTextColor(BLACK, WHITE);
  display.println("\n   Date             ");  
  display.setTextColor(WHITE);
  display.println(" Oct, 2022 GC");

  // Device Name
  infoNameFlash = !infoNameFlash;
  if(infoNameFlash){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE, BLACK);
  }
  display.println("\n  Nano Game Console  ");  

  // Display
  display.display();
}

// A P P S  P A G E 
int appsListY = 0;
int appChoiceIndex = 0;
int totalAppCount = 4;
void appsPage() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, appsListY);
  display.println(" Apps ");
  if(appChoiceIndex == 1){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Converter ");
  if(appChoiceIndex == 2){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Music Player ");
  if(appChoiceIndex == 3){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Timer ");
  if(appChoiceIndex == 4){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Calendar ");

  display.display();
}

// Apps
// Converter
int numConverterX = 0;
int numConverterY = 0;
int numConvValue = 0;
void numberConverter() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(WHITE);

  display.print("DEC: ");
  display.println(numConvValue);

  display.print("HEX: ");
  display.println(numConvValue, HEX);

  display.print("OCT: ");
  display.println(numConvValue, OCT);

  display.print("BIN: ");
  display.println(numConvValue, BIN);

  display.display();

  if(digitalRead(upBtn) == HIGH){
    numConvValue++;
  }
  if(digitalRead(downBtn) == HIGH){
    numConvValue--;
  }
  if(digitalRead(rightBtn) == HIGH){
    numConvValue *= 2;
  }
  if(digitalRead(leftBtn) == HIGH){
    numConvValue /= 2;
  }
  if(digitalRead(bBtn) == HIGH){
    state = 1;
    appsListY = 0;
    appChoiceIndex = 0;
  }
}

// Timer
unsigned long timerCount = 0;
int timerPaused = true;
int timerLight = 11;
void timer() {
  timerLight++;
  if(timerLight > 13){
    timerLight = 11;
  }
  if(!timerPaused) {
    digitalWrite(timerLight, HIGH);
    delay(100);
    digitalWrite(timerLight, LOW);
  } else {
    digitalWrite(11, HIGH);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(" Timer ");
  display.setTextSize(2);
  display.setCursor(2, 10);
  if(!timerPaused){
    timerCount = millis();
  }
  int second = timerCount / 1000;
  int minute = second / 60;
  // if(second >= 60){
  //   second = timerCount % 60;
  // }
  display.print(minute);
  display.print(":");
  display.print(second);
  display.print(":");
  display.print(timerCount);
  display.display();

  if(digitalRead(aBtn) == HIGH){
    timerPaused = !timerPaused;
  }
  if(digitalRead(bBtn) == HIGH){
    if(timerCount == 0 && timerPaused == true){
      state = 1;
      appsListY = 0;
      appChoiceIndex = 0;
    } else {
      timerCount -= timerCount;
      timerPaused = true;
    }
  }
}


// Calendar
int monthIndex = 1;
char *monthNames[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int monthDates[12] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30};
char *weekNames[7] = {"M","T", "W", "T", "F", "S", "S"};
int calendarY = 0;
int calendarLineCounter = 0;

void calendar() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, calendarY);
  display.print("     Calendar      ");
  display.setTextColor(WHITE);
  display.setCursor(35, calendarY + 10);
  display.println(monthNames[monthIndex]);
  display.setCursor(6, calendarY + 20);
  // Week Names
  for(int i = 0; i < 7; i++){
    display.print(weekNames[i]);
    display.print("  ");
  }
  // Days
  display.setCursor(5, calendarY + 30);
  // for(int i = 1; i <= monthDates[monthIndex]; i++){
  //   calendarLineCounter++;
  //   if(calendarLineCounter > 7){
  //     display.println(" ");
  //     calendarLineCounter = 0;
  //   }
  //   display.print(i);
  //   display.print(" ");
  // }
  display.print("1  2  3  4  5  6  7 \n 8  9 10 11 12 13 14 \n15 16 17 18 19 20 21 \n22 23 24 25 26 27 28 \n29 30 31");

  display.display();

  if(digitalRead(upBtn) == HIGH){
    calendarY += 5;
  }
  if(digitalRead(downBtn) == HIGH){
    calendarY -= 5;
  }
  if(digitalRead(rightBtn) == HIGH){
    monthIndex++;
  }
  if(digitalRead(leftBtn) == HIGH){
    monthIndex--;
  }
  if(digitalRead(bBtn) == HIGH){
    state = 1;
    appsListY = 0;
    appChoiceIndex = 0;
  }
}

// L O O P
void loop() {
  // Clear the buffer.
	display.clearDisplay();

  // S T A T E S
  // Main Menu - State 1
  if(state == 0){
    if(digitalRead(leftBtn) == HIGH){
      mainMenuItem--;
      if(mainMenuItem < 1){
        mainMenuItem = 2;
        mainMenuPage--;
        if(mainMenuPage < 1){
          mainMenuPage = 2;
          mainMenuItem = 2;
        }        
      }
    }    
    if(digitalRead(rightBtn) == HIGH){
      mainMenuItem++;      
      if(mainMenuItem > 2){
        mainMenuItem = 1;
        mainMenuPage++;
        if(mainMenuPage > 2){
          mainMenuPage = 1;
          mainMenuItem = 1;          
        }        
      }
    }  
    mainMenu(mainMenuPage, mainMenuItem); 

    if(digitalRead(aBtn) == HIGH){
      // Apps page
      if(mainMenuPage == 1 && mainMenuItem == 1){
        state = 1;
        appsListY = 0;
        appChoiceIndex = 0;
      }
      // Games page
      if(mainMenuPage == 1 && mainMenuItem == 2){
        state = 2;
      }
      // Extra page
      if(mainMenuPage == 2 && mainMenuItem == 1){
        state = 3;
      }
      // Info page
      if(mainMenuPage == 2 && mainMenuItem == 2){
        state = 4;
      }
    } 
  }

  // Apps Page - State 2
  if(state == 1){
    if(digitalRead(upBtn) == HIGH){
      appChoiceIndex--;
      if(appChoiceIndex == 0){
        appChoiceIndex = totalAppCount;
        appsListY = -15;
      }
      if(appChoiceIndex <= totalAppCount - 2){
        appsListY += 8;
      }
    }
    if(digitalRead(downBtn) == HIGH){
      appChoiceIndex++;
      if(appChoiceIndex >= 3){
        appsListY -= 8;
      }      
      if(appChoiceIndex > totalAppCount){
        appChoiceIndex = 1;
        appsListY = 0;
      }
      
    }
    if(digitalRead(aBtn) == HIGH){
      // Converter
      if(appChoiceIndex == 1){
        state = 5;
      }
      // Timer
      if(appChoiceIndex == 3){
        state = 6;
      }
      // Calendar
      if(appChoiceIndex == 4){
        state = 7;
      }
    }
    if(digitalRead(bBtn) == HIGH){
      goBackToMainMenu(1, 1);
    }
    appsPage();
  }

  // Info Page - State 4
  if(state == 4){
    if(digitalRead(leftBtn) == HIGH){
      infoPageX += 6;
    }
    if(digitalRead(upBtn) == HIGH){
      infoPageY += 6;
    }
    if(digitalRead(downBtn) == HIGH){
      infoPageY -= 6;
    }
    if(digitalRead(rightBtn) == HIGH){
      infoPageX -= 6;
    }
    if(digitalRead(bBtn) == HIGH){
      goBackToMainMenu(2, 2);
    }
    infoPage();
  }


  // App 1 - Converter
  if(state == 5){
    numberConverter();
  }
  // App 2 - Timer
  if(state == 6){
    timer();
  }
  // App 3 - Calendar
  if(state == 7){
    calendar();
  }
}













