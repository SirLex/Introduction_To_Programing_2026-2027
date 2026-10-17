#include <iostream>
using namespace std;

int main(){
    int d, v1, v2;

    cout << "Enter the speed of the slower person: ";
    cin >> v1;

    cout << "Enter the speed of the faster person: ";
    cin >> v2;

    cout << "Enter the distance between the two people: ";
    cin >> d;
    

    int t = d / (v2 - v1);

    cout << "The time it takes for the second person to catch up to the first person is: " << t << " hours." << endl;

}