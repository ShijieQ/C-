#include<bits/stdc++.h>

using namespace std;

class base {
private:
    int val;
public:
    base(int a) {
        this->val = a ;
        cout<<"base construction"<<endl;
    }
    virtual ~base() {
        cout<<"base destruction"<<endl;
    }
};

class derive: public base {
private:
    int val;
public:
    derive(int a):base(a) {
        this->val = a;
        cout<<"derive construction"<<endl;
    }
    ~derive() {
        cout<<"derive destruction"<<endl;
    }
};

int main() {
    derive d(3);
    base* bp = &d;
    delete bp;
    return 0;
}