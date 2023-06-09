#include <SPI.h>                                         
#include <nRF24L01.h>                                    
#include <RF24.h>  
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        3
#define NUMPIXELS 64

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500   

#include "Common.h"
#include "MotorControl.h"

RF24 radio(8, 9); // nRF24L01+ (CE, CSN)
int data[5]; 

void setup(){
  initMotorControl();
  Serial.begin(9600);
    
  radio.begin();                                        
  radio.setChannel(5);                                  // Указываем канал приёма данных (от 0 до 127), 5 - значит приём данных осуществляется на частоте 2,405 ГГц (на одном канале может быть только 1 приёмник и до 6 передатчиков)
  radio.setDataRate     (RF24_1MBPS);                   // Указываем скорость передачи данных (RF24_250KBPS, RF24_1MBPS, RF24_2MBPS), RF24_1MBPS - 1Мбит/сек
  radio.setPALevel      (RF24_PA_HIGH);                 // Указываем мощность передатчика (RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBm, RF24_PA_MAX=0dBm)
  radio.openReadingPipe (1, 0x3234567890LL);            // Открываем 1 трубу с идентификатором 0x1234567890 для приема данных (на одном канале может быть открыто до 6 разных труб, которые должны отличаться только последним байтом идентификатора)
  radio.startListening  ();                             // Включаем приемник, начинаем прослушивать открытую трубу
  //  radio.stopListening   ();                         // Выключаем приёмник, если потребуется передать данные

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop(){
  Command cmd;
  uc tmp[2] = {37, 49};
  uc test = 0;
    if(radio.available()){                                // Если в буфере имеются принятые данные
        radio.read(&data, sizeof(data));                  // Читаем данные в массив data и указываем сколько байт читать
        setPowerOnMotors(data[0], data[1]);
        Serial.println(data[4]);
        Serial.println(data[0]);
        Serial.println(data[1]);         
    }
  pixels.clear();
  if(data[4]) {
    for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(16, 16, 16));
    }
    pixels.show();
  } else {
    for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show();

  }
}