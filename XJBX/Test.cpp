#include <iostream>
using namespace std;

class A {
public:
    void print() {
        cout << "This is A." << endl;
    }
};

class B: public A {
public:
    void print() {
        cout << "This is B." << endl;
    }
};

int main() {
    A a;
    B b;
    A *p1 = &a;
    B *p2 = &b;
    p1->print();
    p2->print();
    return 0;
}
