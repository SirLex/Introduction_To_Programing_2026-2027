#include <iostream>
using namespace std;

int gcd(int a, int b){

    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    int gcd = a;
    return gcd;

}

int lcm(int a, int b){

   
    int lcm = a /  gcd(a, b) * b;
    return abs(lcm);

}

int main() {

    cout << gcd(15, 25) << endl;
    cout << gcd(16, 24) << endl;
    cout << lcm(6, 9) << endl;
    cout << lcm(-12, 15) << endl;


    

}