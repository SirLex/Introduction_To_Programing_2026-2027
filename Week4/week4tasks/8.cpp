#include <iostream>
using namespace std;

bool isPrime(unsigned int number){

    if (number < 2){
        return false;
    } else {
        for (unsigned int i = 2; i * i <= number; i++){
            if (number % i == 0){
                return false;
            } 
        }
    }

    return true;

}

void printPrimesUpTo(unsigned int n){
    
    for (int i = 1; i <= n; i++){
        if (isPrime(i) == true)
            cout << i << " ";
    }

    cout << endl;

}

int main(){

    cout << boolalpha;
    cout << isPrime(25) << endl;
    cout << isPrime(7) << endl;
    cout << isPrime(1) << endl;
    printPrimesUpTo(30);

}