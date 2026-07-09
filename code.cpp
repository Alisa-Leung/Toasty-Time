#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// pin definitions
// tft display
#define TFT_RST  10
#define TFT_DC   8
#define TFT_SCLK 21
#define TFT_MOSI 20
#define TFT_CS   -1
// keyboard switch
#define KB       3
// rotary encoder
#define KY_CLK   2
#define KY_DT    1
#define KY_SW    0
// buzzer
#define BZ       6

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//state machine
enum TimerState {
    SETTING,
    COUNTDOWN,
    ALARM
}
TimerState currentState = SETTING;

volatile long totalSeconds = 0;
long lastTotalSeconds = -1;
unsigned long countdownStartMillis = 0;
long initialCountdownSeconds = 0;

volatile int encoderDeltaSteps = 0;
int lastClkState;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50
int lastKbState = HIGH;

void encoderISR() {
  int clkState = digitalRead(KY_CLK);
  if (clkState != lastClkState && clkState == LOW) {
    if (digitalRead(KY_DT) != clkState) {
      encoderDeltaSteps++;
    } else {
      encoderDeltaSteps--;
    }
  }
  lastClkState = clkState;
}

void setup() {
  Serial.begin(115200);
  
  tft.init(76, 284);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.setTextSize(3);
  Serial.println("TFT Initialized!");

  pinMode(KB, INPUT_PULLUP);
  pinMode(KY_CLK, INPUT_PULLUP);
  pinMode(KY_DT, INPUT_PULLUP);
  pinMode(KY_SW, INPUT_PULLUP);
  pinMode(BZ, OUTPUT);
  digitalWrite(BZ, LOW);

  lastClkState = digitalRead(KY_CLK);
  attachInterrupt(digitalPinToInterrupt(KY_CLK), encoderISR, CHANGE);
}

void loop() {
  int reading = digitalRead(KB);
  bool kbPressed = false;

  if (reading != lastKbState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastKbState == HIGH) {
      kbPressed = true;
    }
    lastKbState = reading;
  }
  
  // state machine, will make features look cooler when i get the screen :)
  switch (currentState) {
    case SETTING:
      if (encoderDeltaSteps != 0) {
        noInterrupts();
        int steps = encoderDeltaSteps;
        encoderDeltaSteps = 0;
        interrupts();
        long stepSize = (totalSeconds <= 600) ? 60 : 300;
        // increase/decrease time in increments of 5 mins unless below 10 mins, then increments of 1 min
        for (int i = 0; i < abs(steps); i++) {
          stepSize = (totalSeconds <= 600) ? 60 : 300;
          if (steps > 0) {
            totalSeconds += stepSize;
          } else {
            totalSeconds -= stepSize;
          }
          if (totalSeconds < 0) {
            totalSeconds = 0;
            break;
          }
        }
      }
      if (kbPressed && totalSeconds > 0) {
        initialCoundownSeconds = totalSeconds;
        countdownStartMillis = millis();
        currentState = COUNTDOWN;
        tft.fillScreen(ST77XX_BLACK);
        tft.setTextColr(ST77XX_YELLOW, ST77XX_BLACK);
      }
      break;

    case COUNTDOWN:
      encoderDeltaSteps = 0;
      {
        unsigned long elapsed = (millis() - countdownStartMillis) / 1000;
        long remaining = intitialCountdownSeconds = elapsed;
        if (remaining <= 0) {
          totalSeconds = 0;
          currentState = ALARM;
          tft.fillScreen(ST77XX_RED);
          tft.setTextColor(ST77XX_WHITE, ST77XX_RED);
        } else {
          totalSeconds = remaining;
        }
      }
      break;

    case ALARM:
      // alarm
      if ((millis() / 250) % 2 == 0) {
        tone(BZ, 2000);
      } else {
        noTone(BZ);
      }
      // turn off
      if (kbPressed) {
        noTone(BZ);
        digitalWrite(BZ, LOW);
        totalSeconds = 0;
        currentState = SETTING;
        tft.fillScreen(ST77XX_BLACK);
        tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
      }
      break;
  
  // update display
  if (totalSeconds != lastTotalSeconds || currentState == ALARM) {
    lastTotalSeconds = totalSeconds;

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) /60;
    int seconds = totalSeconds % 60;

    tft.setCursor(0, 0);

    if (hours < 10) tft.print("0");
    tft.print(hours);
    tft.print(":");

    if (minutes < 10) tft.print("0");
    tft.print(minutes);
    tft.print(":");

    if (seconds < 10) tft.print("0");
    tft.print(seconds);

    tft.print("   ");
  }
}