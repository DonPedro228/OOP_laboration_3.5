#include <iostream>
#include "Array.h"
#include "Money.h"
using namespace std;

int main() {
    cout << "Input count of nominal: ";
    int count;
    cin >> count;
    Money money(count);

    for (int i = 0; i < count; ++i) {
        cout << "Enter details for money unit " << i + 1 << ": ";
        cin >> money[i];
    }

    cout << "Money units entered by user:" << endl;
    cout << money << endl;

    return 0;
}