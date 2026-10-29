#include <iostream>
using namespace std;

char toUpper (char symbol) {
    if (symbol >= 97 && symbol <= 122){
        return symbol -= ('a' - 'A');
    } else {
        return symbol;
    }
}

char toLower (char symbol) {
    if (symbol >= 65 && symbol <= 90){
        return symbol += ('a' - 'A');
    } else {
        return symbol;
    }
}


int main() {
    cout << toUpper('a') << endl;
    cout << toLower('A') << endl;
    cout << toLower('&') << endl;
}