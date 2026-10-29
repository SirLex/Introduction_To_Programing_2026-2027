#include <iostream>
using namespace std;

int absoluteValue (int a){
    int absoluteNum = a >= 0 ? a : (-1) * a;
    return absoluteNum;
}

double absoluteValue (double a){
    double absoluteNum = a >= 0 ? a : (-1) * a;
    return absoluteNum;
}

int main() {
    cout << absoluteValue(-7) << endl;
    cout << absoluteValue(13) << endl;
    cout << absoluteValue(-2.5900000) << endl;
}