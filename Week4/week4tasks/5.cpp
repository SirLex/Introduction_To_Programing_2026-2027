#include <iostream>
using namespace std;

void printLine(int Length = 10, char symbol = '-'){
    for (int i = 0; i < Length; i++){
        cout << symbol;
    }

    cout << endl;
}

void printRectangle(int width, int height, char symbol = '*'){
    for (int i = 0; i < height; i++){
        printLine(width, symbol);
    }

    

}

int main() {
    
    
    printRectangle(4, 2);
}