#include <iostream>
#include <vector>

using namespace std;

// Class declaration
class MyClass {
public:
    MyClass(); // Default constructor
    MyClass(int num); // Constructor with parameter
    ~MyClass(); // Destructor

    void myMethod(); // Method declaration
    void setNum(int num); // Setter method
    int getNum(); // Getter method
    Node createNode();

private:
    int num_; // Private member variable
};

// Default constructor definition
MyClass::MyClass() {
    num_ = 0;
    cout << "Default constructor called." << endl;
}

// Constructor with parameter definition
MyClass::MyClass(int num) {
    num_ = num;
    cout << "Constructor with parameter called." << endl;
}

// Destructor definition
MyClass::~MyClass() {
    cout << "Destructor called." << endl;
}

// Method definition
void MyClass::myMethod() {
    cout << "myMethod() called." << endl;
}

// Setter method definition
void MyClass::setNum(int num) {
    num_ = num;
}

Node MyClass::createNode(){
    
}

// Getter method definition
int MyClass::getNum() {
    return num_;
}

int main() {
    // Object creation using default constructor
    MyClass obj1;

    // Object creation using constructor with parameter
    MyClass obj2(10);

    // Method call
    obj1.myMethod();

    // Setter method call
    obj1.setNum(5);

    // Getter method call
    cout << "num_ value of obj1: " << obj1.getNum() << endl;

    // Vector of objects
    vector<MyClass> vec;
    vec.push_back(obj1);
    vec.push_back(obj2);

    return 0;
}
