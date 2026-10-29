#include <iostream>
using namespace std;

int reverse(unsigned int number) {
    int result = 0;
    for (int i = 0; number != 0; i++){
        result = result * 10 + number % 10;
        number /= 10;
    }

    return result;

}

bool isPalindrome(unsigned int number){
    if(number == reverse(number)){
        return true;
    }

    return false;
}

int main() {
    cout << reverse(123) << endl;
    cout << reverse(1200) << endl;
    cout << boolalpha;
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(1231234) << endl;
}