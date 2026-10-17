#include <iostream>
using namespace std;

int main(){

    int a;

    cout << "Enter a three digit number: ";

    cin >> a;

    cout << (a / 100 == a % 10) << endl;

}