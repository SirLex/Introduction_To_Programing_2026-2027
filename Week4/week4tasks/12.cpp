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

unsigned int concat(unsigned int first, unsigned int second){
    int third = first * power(10, getLength(second)) + second;
    return third;
}

int main() {
    cout << concat(123, 456) << endl;
    cout << concat(5, 0) << endl;
}