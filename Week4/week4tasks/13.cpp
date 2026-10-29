#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void sortThree(int& a, int& b, int& c){
    if (a > b){
        swap(a, b);
    } 
    
    if (b > c){
        swap(b, c);
    }
    
    if(a > b){
        swap(a, b);
    }
}

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    sortThree(a, b, c);
    cout << a << " " << b << " " << c << endl;
}