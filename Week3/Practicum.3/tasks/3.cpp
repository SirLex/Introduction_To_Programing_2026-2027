#include <iostream>
using namespace std;

int main() {
    int month, year;
    cout << "Enter month and year: ";
    cin >> month >> year;

    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            cout << "31\n";
            break;
        case 2:
            if (year % 4 == 0  && year % 100 || year % 400 == 0){
                cout << "29\n";
                break;
            }else{
                cout << "28\n";
                break;
            }

        default:
            cout << "30\n";
            break;
    }

}