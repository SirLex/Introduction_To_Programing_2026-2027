#include <iostream>
using namespace std;

int main () {

    int counter = 0;
    int opit;
    cout << "Enter PIN (3 tries): ";

    while (counter != 3){

        cin >> opit;
        switch (opit){
            case 1312: "Correct!\n"; break;
            default: counter++; break;
        }

    }

    cout << "TOO MANY TRIES!\n";

}