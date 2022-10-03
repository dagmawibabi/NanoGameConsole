#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

// G L O B A L S
int state = 4;
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
  mainMenu(1, 1);
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


// L O O P
void loop() {
  // Clear the buffer.
	display.clearDisplay();

  // S T A T E S
  // Main Menu - State 1
  if(state == 0){
    // Main Menu
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
      // Info page
      if(mainMenuPage == 2 && mainMenuItem == 2){
        state = 4;
      }
    } 
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
      state = 0;
      mainMenuItem = 1;
      mainMenuPage = 1;
    }
    infoPage();
  }
  
}


