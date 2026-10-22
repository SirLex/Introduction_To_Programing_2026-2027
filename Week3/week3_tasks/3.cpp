#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int n;

    cout << "Enter an int: ";
    cin >> n; 

    while (n != 0){
        sum+=n;
        cin >> n;
    }    

    cout << sum << endl;

}