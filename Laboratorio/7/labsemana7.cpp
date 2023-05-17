#include <iostream>
#include <string>
#include <charconv>
#include <iomanip>
using namespace std;

//Ex4
struct Node {
    int data;
    Node* next;
};

void addNewNode(Node** head, int newData) {
    Node* newNode = new Node; // Allocate memory 
    newNode->data = newData; 
    newNode->next = *head;
    *head = newNode;   
}

void printNodes(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void statsNodes(Node* head) {
    int sum = 0;
    int avg = 0;
    int product = 1;
    double total = 0;
    while (head != nullptr) {
        sum = sum + head->data;
        product = product  * head->data;
        head = head->next;
        total = total + 1;
    }
    cout << "sum:" << sum << endl;
    cout << "avg:" << (sum/total) << endl;
    cout << "product:" << product << endl;
    std::cout << std::endl;
}

//End Ex4

/* Fuction for get integer and string - io interaction, */
/* include <iomanip>,  std::setprecision(2) << value    */
/* https://en.cppreference.com/w/cpp/io/manip/setprecision */
void getIntegerAndStringInformation(){
    int number = 0;
    string data;
    cout << "Number?:";
    cin >> number;
    cout << "String?:";
    cin >> data;
    cout << "Number is: " << number << " and String is: " << data << endl;
}

/* AVG calculator*/
void avgCalculator(){
    int values = 0;
    int tempValues = 0;
    double totalNumbers;
    int count;
    float avg;
    cout << "totalNumbers:?";
    cin >> totalNumbers;
    for (count = 0; count < totalNumbers ; count++) {
        cout  << "What number?";
        cin >> tempValues;
        values = values + tempValues;
    }
    cout << values << endl;
    avg = values / totalNumbers;
    cout << "precision double/float:" << std::cout.precision() << endl;
    cout << "AVG:" << std::setprecision(2) <<avg << endl;
    cout << "precision double/float:" << std::cout.precision() << endl;
    

}

int myStrLenFuntion(string value){
    //while / for '\0'
    return value.length();
}

/* Algorithm created to work with a list and read strings from the keyboard to transform them to integers. */
/* 
    dependencies:
    struct Node 
    void addNewNode(Node** head, int newData)
    void printNodes(Node* head)
    void statsNodes(Node* head) */
void statsFromIntegers(){
    // char to int and value for exit
    //xithttps://en.cppreference.com/w/cpp/utility/from_chars
    //g++ -std=c++17 labsemana7.cpp 
    Node* head = nullptr;
    //testing
    int flag = 1;
    int intValue = 0;
    string option;
    
    while ( flag == 1) {
        cout << "Number or q for exit?:";
        cin >> option;
        int num = 0;
        auto [p, ec] = std::from_chars(option.data(), option.data() + option.size(), intValue);
        if (ec == std::errc()) {
            addNewNode(&head,intValue);
        } else {
            //Conversion to integer fail, exit
            flag = 0;
        }
    }
    cout << "List of stats: ";
    printNodes(head);
    statsNodes(head);
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

bool isPalindrome(string str) {
    if (str.length() <= 1) {
        return true;
    }
    if (str[0] == str[str.length()-1]) {
        return isPalindrome(str.substr(1, str.length()-2));
    }
    return false;
}

/* Main function of Lab 7*/
int main (){
    //Ex1
    getIntegerAndStringInformation();
    //Ex2
    avgCalculator();
    //Ex3
    string value;
    cout << "String?:";
    cin >> value;
    cout << "len:" << myStrLenFuntion(value) << endl;

    //Ex4
    statsFromIntegers();

    //Ex5
    int valueFactorial;
    cout << "Factorial of (integer)?:";
    cin >> valueFactorial;
    cout << factorial(valueFactorial);

    //Ex6
    int number;
    cout << "Fibonnaci (integer)?:";
    cin >> number;
    cout << "Fibonacci sequence at " << number << " is " << fibonacci(number) << endl;

    //Ex7
    string input;
    cout << "Enter a word or phrase: " << endl;
    cin >> input;
    if (isPalindrome(input)) {
        cout << input << " is a palindrome" << endl;
    } else {
        cout << input << " is not a palindrome" << endl;
    }

    return 0;

}