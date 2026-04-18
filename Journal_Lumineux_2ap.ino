#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 10

MD_Parola display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);


SoftwareSerial BT(2, 3);


#define PIN_ROUGE 4
#define PIN_VERT 5

#define MESSAGE_MAX 100
char message[MESSAGE_MAX] = "Pret !";
bool nouveauMessage = false;

void setup() {
  display.begin();
  display.setIntensity(3);
  display.displayClear();
  display.setSpeed(100);  // Vitesse initiale
  display.displayText(message, PA_LEFT, display.getSpeed(), 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);

  BT.begin(9600);

  pinMode(PIN_ROUGE, OUTPUT);
  pinMode(PIN_VERT, OUTPUT);

  
  digitalWrite(PIN_ROUGE, LOW);
  digitalWrite(PIN_VERT, HIGH);
}

void loop() {
  static uint8_t index = 0;

  if (BT.available()) {
    char c = BT.read();

    
    if (c == '+') {
      uint16_t speed = display.getSpeed();
      if (speed > 20) display.setSpeed(speed - 10);
    }
    else if (c == '-') {
      uint16_t speed = display.getSpeed();
      if (speed < 500) display.setSpeed(speed + 10);
    }
    
    else if (c == '\n' || c == '\r') {
      message[index] = '\0';
      index = 0;
      nouveauMessage = true;
    } else {
      if (index < MESSAGE_MAX - 1) {
        message[index++] = c;
      }
    }

    
    digitalWrite(PIN_ROUGE, HIGH);
    digitalWrite(PIN_VERT, LOW);
  }

  if (nouveauMessage) {
    display.displayClear();
    display.displayText(message, PA_LEFT, display.getSpeed(), 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    nouveauMessage = false;
  }

  if (display.displayAnimate()) {
    display.displayReset();
  }
}
