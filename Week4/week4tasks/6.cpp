#include <iostream>
using namespace std;

void power(int base, int exponent){
    
    int powernum =  1;

        for (int i = 0; i < exponent; i++){
            powernum *= base;
        }    

    cout << powernum << endl;
    
}

int main() {

    power(8, 0);
    power(4, 5);
    power(5, 2);
   

}