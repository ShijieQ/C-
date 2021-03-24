#include<iostream>
using namespace std;

class Object {
private:
    int count;
public:
    Object(int count = 0) {
        this->count = count;
    }
    Object& operator =(const Object& b) {
        this->count = b.getCount()+1;
    }
    Object& operator ++() {
        (*this).count++;
        return *this;
    }
    Object operator ++(int) {
        Object old = *this;
        ++(*this);
        return old;
    }
    Object operator +(const Object &c) const{
        Object ans(this->count + c.count);
        return ans;
    }
    int getCount() const {
        return count;
    }
};

int main() {
    Object a(1), b(2);
    // a = 1, b = 2
    cout<<"a = "<<a.getCount()<<", b = "<<b.getCount()<<endl;
    a++;
    ++b;
    // a = 2, b = 3
    cout<<"a = "<<a.getCount()<<", b = "<<b.getCount()<<endl;
    // a + b = 5
    Object c = a+b;
    cout<<"a + b = "<<c.getCount()<<endl;
    return 0;
}