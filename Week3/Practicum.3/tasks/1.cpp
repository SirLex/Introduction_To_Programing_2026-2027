#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    int max = x + y;
    
    if (max < x * y){
        max = x * y;
    }else if(max < x - y){
        max = x - y;
    }else if (max < x / y){
        max = x / y;
    }

    cout << max;

}