#include <iostream>

#include "6_2.h"

// main function
int main(int argc, char** argv) {

    // create an object variable and call its constructor
    Car car("Renault");

    // main algorithm
    car.Refuel(100.0);
    std::cout << "Car is refueled, the correct fuel level is " << car.fuel << std::endl;
    while (car.fuel > 0) {
        std::cout << "Car fuel level: " << car.fuel << std::endl;
        if (car.speed < 80) {
            car.Accelerate();
            std::cout << "Car has been accelerated to the speed: " << car.speed << std::endl;
        } else {
            car.Brake();
            std::cout << "Car has been slowed down to the speed: " << car.speed << std::endl;
        }
    }

    std::cout << "Car ran out of the fuel! Slowing down ..." << std::endl;
    while (car.speed > 0) {
        car.Brake();
        std::cout << "Car has been slowed down to the speed: " << car.speed << std::endl;
    }
    std::cout << "Car is stopped!" << std::endl;

    // the object will be automatically destructed returning main function
    return 0;
}