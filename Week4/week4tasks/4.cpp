#include <iostream>
using namespace std;

int toNumber (char symbol) {
    if (symbol >= '0' && symbol <= '9'){
        return symbol - '0';
    }else{
        return -1;
    }
}

char toCharacter (int number) {
    if (number >= 0 && number <= 9){
        return number + '0';
    }else{
        return '\0';
    }
}

int main () {
    cout << toNumber('7') << endl;
    cout << toNumber('!') << endl;
    cout << toCharacter(3) << endl;
}