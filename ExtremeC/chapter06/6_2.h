#ifndef EXTREME_C_EXAMPLES_CHAPTER_6_2_H
#define EXTREME_C_EXAMPLES_CHAPTER_6_2_H

class Car {
public:
    // constructor
    Car(const char*);
    // destructor
    ~Car();

    // member function
    void Accelerate();
    void Brake();
    void Refuel(double);

    // data member
    char name[32];
    double speed;
    double fuel;
};

#endif