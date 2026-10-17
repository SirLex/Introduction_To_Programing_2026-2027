#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;

    int a = abs(x2 - x1);
    int b = abs(y2 - y1);

    double area =  a*b;

    cout << "The area of the rectangle formed by the two points is: " << area << endl;
}