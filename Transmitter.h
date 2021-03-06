#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <Arduino.h>
#include "TimerTwo.h"
#include "Constants.h"
#include "LEDBitmap.h"

typedef struct Frame{
  size_t size = 0;
  uint8_t* data;
} Frame;

class Transmitter
{
  public:
    Transmitter(int frequency = 1000);
    virtual ~Transmitter() {  };

  public: //methods
    int sendData(LEDBitmap &image);
    int sendData(String &string);
    void transmitBit();
    void start();
    void stop();
    int setFrequency(int frequency);
    bool lastTransmissionComplete();
    bool isStarted() { return _active; };
    void setPin(int pin);
    int getPin();

  private: //members
    uint8_t _state;
    Frame _frame;
    uint16_t _pos;
    uint8_t _manHalf;
    int _pin;
    bool _busy;
    bool _active;
    static Transmitter *_instance = NULL;

    int _prepFrame(LEDBitmap &image);
    int _prepFrame(String &string);
    uint8_t _buildBitFrame(uint8_t* frame, uint8_t &size);
    static void _transmitBit();

};

#endif
