// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

char receivedChar;
ArduinoLEDMatrix matrix;
char incoming[256];
int stringLength = 0; 

void setup() {
  matrix.begin();

  Serial.begin(9600);

  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(100);

  const char text[] = "  UNO r4  ";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  Serial.println(text);
  
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
}

void loop() {
  while (Serial.available()) {
      receivedChar = Serial.read();

      if (stringLength==0 || stringLength<=256){
      incoming[stringLength] = receivedChar;  // Add character to string
      stringLength++;
  }
}
  // Make it scroll!
  matrix.beginDraw();
  
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);

  // add the text
  //char text[] = a;
  matrix.textFont(Font_5x7);
  matrix.beginText(1, 1, 0xFFFFFF);
  Serial.println(receivedChar);
  matrix.println(incoming);
  matrix.endText(SCROLL_LEFT);

  matrix.endDraw();
  
  for(int i=0;i<(stringLength-1);i++){
    incoming[i]=0;

  }
  stringLength=0;
}