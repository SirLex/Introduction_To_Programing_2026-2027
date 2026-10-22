#include <iostream>
using namespace std;

int main() {
    double a, b;
    char symbol;
    cout << "Enter a, a symbol and b: ";
    cin >> a >> symbol >> b;

    switch(symbol){
        case '+': cout << a + b << endl ;break;
        case '-': cout << a - b << endl; break;
        case '*': cout << a * b << endl; break;
        case '/': {if (b == 0){
            cout << "Invalid operation!\n";
        }else {
            cout << a / b << endl;
        }break;
            
        default:
            cout << "invalid operation\n";
 
        }
}