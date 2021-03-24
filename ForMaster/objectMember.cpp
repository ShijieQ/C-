#include<iostream>

using namespace std;

class A {
private:
    int x;
public:
    A(int a) {
        x = a;
        cout<<"A: x = "<<a<<endl;
    }
};

class B {
private:
    A a1, a2;
    int y;
public:
    B(int a, int b, int c):a2(b), a1(a) {
        y = c;
        cout<<"B: y = "<<c<<endl;
    }
};

int main() {
    B obj(10, 20, 30);
    return 0;
}