#include <reg51.h>

sbit moistureSensor = P1^0; // Soil moisture sensor connected to P1.0
sbit waterPump = P1^1;     // Water pump connected to P1.1

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);
}

void main() {
    moistureSensor = 1; // Set as input
    waterPump = 0;     // Initialize pump off

    while (1) {
        if (moistureSensor) {
            // Soil is dry (high resistance)
            waterPump = 1; // Turn on water pump
        } else {
            // Soil is wet (low resistance)
            waterPump = 0; // Turn off water pump
        }
        delay(1000); // Delay for 1 second
    }
}