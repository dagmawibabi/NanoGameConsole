
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
int c = 261;
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 784;
int gSH = 830;
int aH = 880;

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

// G A M E S  P A G E 
int gamesListY = 0;
int gamesChoiceIndex = 0;
int totalGameCount = 4;
void gamesPage() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, gamesListY);
  display.println(" Games ");
  if(gamesChoiceIndex == 1){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Starwars ");
  if(gamesChoiceIndex == 2){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Pong ");
  if(gamesChoiceIndex == 3){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Alien Invasion ");
  if(gamesChoiceIndex == 4){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Flappy Birds ");

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
int calendarY = 0;
int monthIndex = 0;
char *weekNames[7] = {"M","T", "W", "T", "F", "S", "S"};
int monthDates[12] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30};
char *monthNames[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
void calendar() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0, calendarY);
  display.print("       Calendar      ");
  display.setTextColor(WHITE);
  display.setCursor(52, calendarY + 10);
  display.println(monthNames[monthIndex]);
  display.setCursor(6, calendarY + 20);
  // Week Names
  for(int i = 0; i < 7; i++){
    display.print(weekNames[i]);
    display.print("  ");
  }
  // Days
  display.setCursor(5, calendarY + 30);
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
    if(monthIndex >= 12){
      monthIndex = 0;
    }
  }
  if(digitalRead(leftBtn) == HIGH){
    monthIndex--;
    if(monthIndex <= 0){
      monthIndex = 11;
    }
  }
  if(digitalRead(bBtn) == HIGH){
    state = 1;
    appsListY = 0;
    appChoiceIndex = 0;
  }
}

// G A M E S 
// Starwars
int enemyShipY = 15;
int playerShipY1 = 10;
int playerShipY2 = 15;
int playerShipY3 = 12;
int reverseShip = false;
int curBulletX = 0;
int curBulletY = 10;
int enemyBulletX = 0;
int enemyBulletY = 10;
int starWarsScore = 0;
int starWarsHealth = 5;
bool gameOver = false;
void beep(int note, int duration){
  tone(10, note, duration);
  delay(duration);
  noTone(10);
  delay(50); 
}
void starwarsGame() {
  // reset
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  // clear
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  if(starWarsHealth <= 0){
    gameOver = true;
  }
  if(digitalRead(aBtn) == HIGH){
      gameOver = false;
      starWarsScore = 0;
      starWarsHealth = 5;
  } 
  if(digitalRead(bBtn) == HIGH){
    state = 1;
    gamesListY = 0;
    gamesChoiceIndex = 0;
  } 
  if(gameOver == true){
    display.setTextSize(2);
    display.setCursor(10, 0);
    display.println("GAME OVER"); 
    display.setTextSize(1);
    display.setCursor(40, 20);
    display.print("Score: "); 
    display.println(starWarsScore); 
    display.display();
    beep(a, 500); 
    beep(a, 500);    
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);  
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);
    delay(500);     
  } else {
    display.drawPixel(50,30,1);
    display.drawPixel(30,17,1);
    display.drawPixel(60,18,1);
    display.drawPixel(55,16,1);
    display.drawPixel(25,43,1);
    display.drawPixel(100,43,1); 
    display.drawPixel(117,52,1);
    display.drawPixel(14,49,1);
    display.drawPixel(24,24,1);
    display.drawPixel(78,36,1);
    display.drawPixel(80,57,1);
    display.drawPixel(107,11,1);
    display.drawPixel(150,11,1);
    display.drawPixel(5,5,1);
    display.drawPixel(8,7,1);
    display.drawPixel(70,12,1);
    display.drawPixel(10,56,1);
    display.drawPixel(70,25,1);
    // score
    display.setCursor(0, 0);
    display.print(starWarsHealth);
    display.print(" - ");
    display.print(starWarsScore);
    // 
    display.drawTriangle(5, playerShipY1, 5, playerShipY2, 15, playerShipY3, WHITE);
    // Enemy Ship
    display.fillCircle(100, enemyShipY, 6, WHITE);
    display.fillCircle(100, enemyShipY, 2, BLACK);
    if(reverseShip == true){
      enemyShipY -= 1;
    } else {
      enemyShipY += 1;
    }
    if(enemyShipY > 22){
      reverseShip = true;
    }
    if(enemyShipY < 10){
      reverseShip = false;
    }

    // control
    if(digitalRead(upBtn) == HIGH){
      playerShipY1 -= 3;
      playerShipY2 -= 3;
      playerShipY3 -= 3;
    }
    if(digitalRead(downBtn) == HIGH){
      playerShipY1 += 3;
      playerShipY2 += 3;
      playerShipY3 += 3;
    }

    // Player Bullet
    curBulletX += 15;
    if(curBulletX > 100){
      curBulletX = 15;
      curBulletY = playerShipY3;
    }
    display.fillRect(curBulletX, curBulletY, 6, 1, WHITE);

    // Enemy Bullet
    enemyBulletX -= 12;
    if(enemyBulletX < 15){
      enemyBulletX = 100;
      enemyBulletY = enemyShipY;
    }
    display.fillRect(enemyBulletX, enemyBulletY, 6, 1, WHITE);

    // check collision
    if(curBulletX >= 90){
      int matchY1 = enemyShipY + 4;
      int matchY2 = enemyShipY - 4;
      if(curBulletY <= matchY1 && curBulletY >= matchY2){
        digitalWrite(12, HIGH);
        tone(10, 500, 20);
        starWarsScore++;
        // delay(100);
      }
    }   
    // check damage
    if(enemyBulletX <= 20){
      int matchY1 = playerShipY3 + 4;
      int matchY2 = playerShipY3 - 4;
      if(enemyBulletY <= matchY1 && enemyBulletY >= matchY2){
        digitalWrite(13, HIGH);
        tone(10, 100, 100);
        starWarsHealth--;
        // delay(100);
      }
    }
    display.display();
  }
}

// E X T R A S 
int extrasListY = 0;
int extrasChoiceIndex = 0;
int totalExtrasCount = 4;
void extrasPage() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, extrasListY);
  display.println(" Extras ");
  if(extrasChoiceIndex == 1){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" 8-Bit Art ");
  if(extrasChoiceIndex == 2){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Extra 2 ");
  if(extrasChoiceIndex == 3){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Extra 3 ");
  if(extrasChoiceIndex == 4){
    display.setTextColor(BLACK, WHITE);
  } else {
    display.setTextColor(WHITE);
  }
  display.println(" Extra 4 ");

  display.display();
}

// Extra apps
int eightBitArtTime = 3000;
void eightBitArt(){
  display.clearDisplay();
  for(int i = 0; i < 40; i++){
    int x = random(128);
    int y = random(64);
    int w = random(128);
    int h = random(64);
    int r = random(10);
    int circleOrRect = random(1, 20);
    if(circleOrRect == 1 || circleOrRect == 2){
      display.drawRect(x, y, w, h, WHITE);
    } 
    if(circleOrRect == 3 || circleOrRect == 4){
      display.fillRect(x, y, w, h, WHITE);
    } 
    if(circleOrRect == 5 || circleOrRect == 6){
      display.fillCircle(x, y, r, WHITE);
    } 
    if(circleOrRect > 6){
      display.drawCircle(x, y, r, WHITE);
    } 
  }
  display.display();
  if(digitalRead(upBtn) == HIGH){
    eightBitArtTime += 100;
  }
  if(digitalRead(downBtn) == HIGH){
    eightBitArtTime -= 100;
    if(eightBitArtTime <= 0){
      eightBitArtTime = 0;
    }
  }
  if(digitalRead(bBtn) == HIGH){
    state = 4;
    extrasListY = 0;
    extrasChoiceIndex = 0;
  }
  interrupts();
  delay(eightBitArtTime);
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

  // Games Page - State 4
  if(state == 2){
    if(digitalRead(upBtn) == HIGH){
      gamesChoiceIndex--;
      if(gamesChoiceIndex == 0){
        gamesChoiceIndex = totalGameCount;
        gamesListY = -15;
      }
      if(gamesChoiceIndex <= totalGameCount - 2){
        gamesListY += 8;
      }
    }
    if(digitalRead(downBtn) == HIGH){
      gamesChoiceIndex++;
      if(gamesChoiceIndex >= 3){
        gamesListY -= 8;
      }      
      if(gamesChoiceIndex > totalGameCount){
        gamesChoiceIndex = 1;
        gamesListY = 0;
      }
      
    }
    if(digitalRead(aBtn) == HIGH){
      // Starwars
      if(gamesChoiceIndex == 1){
        state = 20;
      }
    }
    if(digitalRead(bBtn) == HIGH){
      goBackToMainMenu(1, 1);
    }
    gamesPage();
  }

  // Extras Page - State 3
  if(state == 3){
    if(digitalRead(upBtn) == HIGH){
      extrasChoiceIndex--;
      if(extrasChoiceIndex == 0){
        extrasChoiceIndex = totalExtrasCount;
        extrasListY = -15;
      }
      if(extrasChoiceIndex <= totalExtrasCount - 2){
        extrasListY += 8;
      }
    }
    if(digitalRead(downBtn) == HIGH){
      extrasChoiceIndex++;
      if(extrasChoiceIndex >= 3){
        extrasListY -= 8;
      }      
      if(extrasChoiceIndex > totalExtrasCount){
        extrasChoiceIndex = 1;
        extrasListY = 0;
      }
      
    }
    if(digitalRead(aBtn) == HIGH){
      // 8Bit Art
      if(extrasChoiceIndex == 1){
        state = 8;
      }
    }
    if(digitalRead(bBtn) == HIGH){
      goBackToMainMenu(1, 1);
    }
    extrasPage();
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

  // Apps
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

  // Games
  // Game 1 - Starwars
  if(state == 20){
    starwarsGame();
  }

  // Extras
  if(state == 8){
    eightBitArt();
  }
}
