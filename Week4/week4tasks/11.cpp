#include <iostream>
using namespace std;

int getLength(int number){

    number = abs(number);    
    int counter = 0;

    do{
        number /= 10;
        counter++;
    }while(number != 0);

    return counter;

}

int power(int base, int exponent){
    
    int powernum =  1;

        for (int i = 0; i < exponent; i++){
            powernum *= base;
        }    

    return powernum;
    
}

void getDigitOnPosition(int number, unsigned int position){
    
    if (position >= 1 && position <= getLength(number)) {
        int numpos = (number / power(10, getLength(number) - position)) % 10;
        cout << numpos << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {

    getDigitOnPosition(6289, 3);
    getDigitOnPosition(5, 2);
    getDigitOnPosition(5000, 1);

}