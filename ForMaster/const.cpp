#include<iostream>

using namespace std;

class Test{
public:
    void print() {
        cout<<"not const"<<endl;
    }
    void print() const {
        cout<<"const"<<endl;
    }
};

int main() {
    Test t;
    t.print()
    return 0;
}