#include <iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cout << "Enter four numbers: ";
    cin >> a >> b >> c >> d;

    int sum = 0;
    sum = a * (1 - (a & 1)) +
            b * (1 - (b & 1)) +
            c * (1 - (c & 1)) +
            d * (1 - (d & 1));

    cout << sum << endl;
}