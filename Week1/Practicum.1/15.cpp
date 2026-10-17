#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double a, b, c;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> a >> b >> c;

    double perimeter = a + b + c;
    double s = perimeter / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << "Area: " << area << ", Perimeter: " << perimeter << endl;


}