#include <iostream>
using namespace std;

int main(){

int a, b, c, d;
cout << "Enter four numbers: ";
cin >> a >> b >> c >> d;

cout << (b/a == c/b && c/b == d/c) << endl;

}