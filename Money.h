#pragma once
#include <iostream>
#include "Array.h"
using namespace std;

class Money : public Array {
public:
    Money() : Array(7) {} 

    Money(int initialSize, Money_Unit default_value = Money_Unit()) : Array(initialSize, default_value) {}
};
