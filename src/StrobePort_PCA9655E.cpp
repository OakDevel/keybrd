#include "StrobePort_PCA9655E.h"

/*
configures column port's configuration and output.
*/
StrobePort_PCA9655E::StrobePort_PCA9655E(IOEPort& port)
    : port(port), configurationByteCommand(port.num + 6), outputByteCommand(port.num + 2) {}

void StrobePort_PCA9655E::begin()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(configurationByteCommand);
    Wire.write(0);                              //0=configure as output (for strobe pins and LED)
    Wire.endTransmission();
}

/*
sets activePin pin output to low, does not reset the other pins because they might be used by LEDs.
activePin is port mask, where active pin is 1.
*/
void StrobePort_PCA9655E::setActivePinLow(const uint8_t activePin)
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(outputByteCommand);
    Wire.write(port.outputVal &= ~activePin);
    Wire.endTransmission();
}

/*
sets activePin pin output to high.
activePin is port mask, where active pin is 1.
*/
void StrobePort_PCA9655E::setActivePinHigh(const uint8_t activePin)
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(outputByteCommand);
    Wire.write(port.outputVal |= activePin);
    Wire.endTransmission();
    //todo delayMicroseconds(1500); still 4*bb w/o debouncer prints IOE rows sporadically
}
void StrobePort_PCA9655E::write(const uint8_t pin, const bool level)
{
    if (level == LOW)
    {
        port.outputVal &= ~pin;
    }
    else 
    {
        port.outputVal |= pin;
    }

    Wire.beginTransmission(port.ADDR);
    Wire.write(outputByteCommand);
    Wire.write(port.outputVal);
    Wire.endTransmission();
}
