#include <iostream>
using namespace std;

int main(){
    char letter;
    cout << "Enter a letter: ";
    cin >> letter;

    int order = int(letter) - int('A') + 1; 
    cout << order << endl;
}