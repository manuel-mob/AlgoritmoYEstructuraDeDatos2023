#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    if (str.length() <= 1) {
        return true;
    }
    if (str[0] == str[str.length()-1]) {
        return isPalindrome(str.substr(1, str.length()-2));
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a word or phrase: ";
    getline(cin, input);
    if (isPalindrome(input)) {
        cout << input << " is a palindrome" << endl;
    } else {
        cout << input << " is not a palindrome" << endl;
    }
    return 0;
}
