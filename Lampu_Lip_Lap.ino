#include <WS2812FX.h>

#define NUM_LEDS 300
#define LED_PIN 19
int effect[] = {12,47,51,52,54,10,46,38,54,40,33,18,29,17,44,20,14,41,45,7,2};
int effectspeed[]={1,50,80,60,40,1,5,25,60,10,25,25,25,50,25,60,25,50,25,25,10};
int color[] = {GREEN,BLUE,YELLOW,RED,PURPLE,CYAN};
unsigned int counter = 0;
unsigned int counterc = 0;
#define TIMER_MS 60000
#define TIMER_MSC 2166
WS2812FX ws2812fx = WS2812FX(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// declare global parameters used by Fire2012
bool gReverseDirection = false;
unsigned long last_change = 0;
unsigned long last_changec = 0;
unsigned long now = 0;
void setup() {

Serial.begin(115200);

  // init WS2812FX to use a custom effect
  ws2812fx.init();
  ws2812fx.setBrightness(255);
  ws2812fx.setColor(GREEN);
  ws2812fx.setSpeed(20000);
  ws2812fx.setMode(12);
  ws2812fx.start();
}

void loop() {
  now = millis();

  
  
  if(now - last_change > TIMER_MS) {
    
    ws2812fx.setMode(effect[counter]);
    ws2812fx.setSpeed(effectspeed[counter]*1000);
    
   Serial.print("Effect: ");
   Serial.print(counter);
   Serial.print(" - ");
   Serial.print(effect[counter]);
   Serial.print(", speed: ");
   Serial.println(effectspeed[counter]);
    counter=counter+1;
    if (counter > 20){  
      counter=0;      
        }
    last_change = now;
    }
    
    
  if(now - last_changec > TIMER_MSC) {
    ws2812fx.setColor(color[counterc]);
    
    Serial.print("Color: "); 
    Serial.print(counterc);  
    Serial.print(":"); 
    Serial.println(color[counterc]);  
    counterc=counterc+1;
    if (counterc > 5){  
      counterc=0;     
      }
    last_changec = now;
    }
  
  ws2812fx.service();
 
  }
