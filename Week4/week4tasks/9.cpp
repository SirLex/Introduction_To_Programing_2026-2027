#include <iostream>
using namespace std;

void getLength(int number){

    number = abs(number);    
    int counter = 0;

    do{
        number /= 10;
        counter++;
    }while(number != 0);

    cout << counter << endl;

}

int main() {
    getLength(155);
    getLength(0);
    getLength(-4);
    getLength(5464);
}