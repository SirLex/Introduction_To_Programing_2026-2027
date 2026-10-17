#include <iostream>
using namespace std;

int main(){

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int bigger = (abs(a - b) + (a + b))/2;

    cout << "The bigger number out of " << a << " and " << b << " is: " << bigger << endl;

}