#include<iostream>
using namespace std;

class Test {
private:
    int a, b;
public:
    Test(){}
    Test(int a, int b):a(a), b(b) {}
    void modify(int a, int b) {
        this->a = a;
        this->b = b;
    }
    void display() {
        cout<<"a = "<<a<<", b = "<<b<<endl;
    }
};

void fun(Test test) {
    test.modify(2, 3);
    test.display();
    return;
}

int main() {
    Test t1(1, 2);
    t1.display();
    fun(t1);
    t1.display();
    return 0;
}