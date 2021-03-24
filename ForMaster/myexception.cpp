#include<iostream>
#include<string>

using namespace std;

class MyExpection {
public:
    MyExpection(const string &message):message(message) {}
    ~MyExpection() {}
    const string &getMessage() const {
        return message;
    }

private:
    string message;
};

class Demo {
public:
    Demo() {cout << "Constructor of Demo" << endl;}
    ~Demo() {cout << "Destructor of Demo" << endl;}
};

void func() throw(MyExpection) {
    Demo d;
    cout << "Throw MyExpection in func()" << endl;
    throw MyExpection("exception thrown by func()");
}

int main() {
    cout << "In main function" << endl;
    try {
        func();
    } catch(MyExpection &e) {
        cout << "Caught an exception:" << e.getMessage() << endl;
    }
    cout << "Resume the exception of main()" << endl;
    return 0;
}