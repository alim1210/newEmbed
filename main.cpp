// main.cpp
#include "mbed.h"
#include "Joystick.h"
#include "N5110.h"  
#include "Utils.h"
#include "mainmenu.h"

N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_1, PC_0);
DigitalIn buttonA(BUTTON1); //onboard user button


// Define a function to read the state of the button
int getButtonPress() {
    if (buttonA.read() == 1) { // Assuming active high button
        return 1; // Return a unique identifier for button A
    }
    // If you have more buttons, add additional checks here
    return 0; // Return 0 if no button is pressed
}


int main() {
    lcd.init(LPH7366_1);
    MainMenu mainMenu(lcd); // Create an instance of MainMenu

    while (true) {
        int buttonPressed = getButtonPress(); // You'll define getButtonPress() to detect hardware button inputs
        mainMenu.update(buttonPressed);
        mainMenu.render();
        ThisThread::sleep_for(100ms);; // Simple debounce
    }
}
