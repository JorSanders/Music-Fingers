#include <CapacitiveSensor.h>

#define DEBUG  false

class Finger {
  public:
    int lastValue;
    int threshhold;
    int topValue = 0;
    String symbol;
    CapacitiveSensor sensor = CapacitiveSensor(0, 0);
    Finger() {};
    
    Finger(int writePin, int readPin, int _threshhold, String _symbol) {
      sensor = CapacitiveSensor(readPin, writePin);
      threshhold = _threshhold;
      symbol = _symbol;
    };
    
    void doMeasurement() {
      lastValue = sensor.capacitiveSensorRaw(0xFFFFFFFF);
      if(lastValue > topValue){
        topValue = lastValue;
      }
    };
    bool isActive(){
      if(lastValue > threshhold){
        return true;
      }
      return false;
    }
};

Finger fingers[3]; // match this number to the amount of fingers
int i;

void setup()
{  
  Serial.begin(9600);
  i = 0;

  // Change values here. (readpin, writepin, threshold, symbol)
  fingers[i++] = Finger(2, 3, 2400, "A");
  fingers[i++] = Finger(5, 6, 2400, "B");
  fingers[i++] = Finger(9, 10, 2400, "C");
}

void loop()
{
  for(int j = 0; j<i;j++){
    fingers[j].doMeasurement();
    if(fingers[j].isActive()){
      Serial.print(fingers[j].symbol);
    }else{
      Serial.print("-");
    }
    Serial.print("\t");
  }
  
  if(DEBUG){
    for(int j = 0; j<i;j++){
      Serial.print(fingers[j].lastValue);      
      Serial.print("\t");
      Serial.print(fingers[j].topValue);      
      Serial.print("\t");
    }
  }

  Serial.println();
}
