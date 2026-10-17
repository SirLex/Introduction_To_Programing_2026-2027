#include <iostream>
using namespace std;

int main(){
    char a;
    cout << "Enter a capital letter: ";
    cin >> a;

    cout << char(int(a) + 32) << endl;
}