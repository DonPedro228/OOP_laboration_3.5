#pragma once
#include <string>
using namespace std;

enum class Nominal {
    ONE,
    TWO,
    FIVE,
    TEN,
    TWENTY,
    FIFTY,
    HUNDRED
};

struct Money_Unit
{
    Nominal nominal;
    int count;

    Money_Unit(): nominal(Nominal::ONE), count(0) {}
    Money_Unit(Nominal n, int c) : nominal(n), count(c) {}

    friend ostream& operator<<(ostream& os, const Nominal& nominal);
    friend istream& operator>>(istream& is, Money_Unit& money_unit);
};

class Array
{
private:
	static const int MAX_SIZE = 100;
    Money_Unit elem[MAX_SIZE];
    int size;
public:
    Array() : size(0) {};
    Array(int initialSize, Money_Unit default_value = Money_Unit());

    Money_Unit& operator [] (int index);

    const Money_Unit& operator [] (int index) const;
    void rangeCheck(int index) const;
    Array& operator=(const Array& other);
    friend istream& operator>>(istream& is, Array& arr);
    friend ostream& operator<<(ostream& os, const Array& arr);
    operator string() const;
};