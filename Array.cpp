#include "Array.h"
#include <iostream>
#include <sstream>
using namespace std;

Array::Array(int initialSize, Money_Unit default_value)
{
	if (initialSize > MAX_SIZE) {
		cerr << "Error: Array out of range!" << endl;
		exit(1);
	}
	size = initialSize;
	for (int i = 0; i < size; ++i) {
		elem[i] = default_value;
	}
}

Money_Unit& Array::operator[](int index)
{
	rangeCheck(index);
	return elem[index];
}

const Money_Unit& Array::operator [] (int index) const
{
	rangeCheck(index);
	return elem[index];
}

void Array::rangeCheck(int index) const {
	if (index < 0 || index >= size) {
		cerr << "Error: Index out of bounds\n";
		exit(1);
	}
}

Array& Array::operator=(const Array& other) {
	if (this != &other) {
		size = other.size;
		for (int i = 0; i < size; ++i) {
			elem[i] = other.elem[i];
		}
	}
	return *this;
}

ostream& operator<<(ostream& os, const Nominal& nominal) {
    switch (nominal) {
    case Nominal::ONE:
        os << "ONE";
        break;
    case Nominal::TWO:
        os << "TWO";
        break;
    case Nominal::FIVE:
        os << "FIVE";
        break;
    case Nominal::TEN:
        os << "TEN";
        break;
    case Nominal::TWENTY:
        os << "TWENTY";
        break;
    case Nominal::FIFTY:
        os << "FIFTY";
        break;
    case Nominal::HUNDRED:
        os << "HUNDRED";
        break;
    }
    return os;
}


istream& operator>>(istream& is, Money_Unit& money_unit) {
    int nominal_index;
    is >> nominal_index >> money_unit.count;

    if (nominal_index < 0 || nominal_index >= static_cast<int>(Nominal::HUNDRED) + 1) {
        is.setstate(ios_base::failbit);
        return is;
    }

    money_unit.nominal = static_cast<Nominal>(nominal_index);

    return is;
}


ostream& operator<<(ostream& os, const Array& arr) {
    for (int i = 0; i < arr.size; ++i) {
        os << "Nominal: " << arr.elem[i].nominal << ", Count: " << arr.elem[i].count << endl;
    }
    return os;
}

istream& operator>>(istream& is, Array& arr) {
    for (int i = 0; i < arr.size; ++i) {
        is >> arr.elem[i]; 
    }
    return is;
}

Array::operator string() const {
    std::stringstream ss;
    for (int i = 0; i < size; ++i) {
        ss << "Nominal: ";
        switch (static_cast<int>(elem[i].nominal)) {
        case 0:
            ss << "ONE";
            break;
        case 1:
            ss << "TWO";
            break;
        case 2:
            ss << "FIVE";
            break;
        case 3:
            ss << "TEN";
            break;
        case 4:
            ss << "TWENTY";
            break;
        case 5:
            ss << "FIFTY";
            break;
        case 6:
            ss << "HUNDRED";
            break;
        default:
            ss << "UNKNOWN";
            break;
        }
        ss << ", Quantity: " << elem[i].count << endl;
    }
    return ss.str();
}
