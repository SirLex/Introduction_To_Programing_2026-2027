#include <iostream>
using namespace std;

int main () {
    int month;
    cout << "Enter month number: ";
    cin >> month;

    switch(month){
        case 12: case 1: case 2:
            cout << "winter";
            break;
        case 3: case 4: case 5:
            cout << "spring";
            break;
        case 6: case 7: case 8:
            cout << "summer";
            break;
        case 9: case 10: case 11:
            cout << "autumn";
            break;
        default:
            cout << "Invalid input";
            break;
    }

}