#include <iostream>
using namespace std;

bool isDigit (char symbol) {
    if (symbol >= 48 && symbol <= 57){
        return true;
    } else {
        return false;
    }
}

bool isLower (char symbol) {
    if (symbol >= 97 && symbol <= 122){
        return true;
    } else {
        return false;
    }
}

bool isUpper (char symbol) {
    if (symbol >= 65 && symbol <= 90){
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << isDigit('a') << endl;
    cout << isDigit('0') << endl;
    cout << isUpper('D') << endl;
    cout << isLower('D') << endl;
}