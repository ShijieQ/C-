#include<iostream>

using namespace std;

class Object {
private:
    int count;
public:
    Object(int count = 0) {
        this->count = count;
    }
    int getCount() const {
        return count;
    }
    void setCount(int value) {
        count = value;
    }
    friend istream& operator >>(istream &in, Object& a);
    friend ostream& operator <<(ostream &out, const Object& a);
    friend Object& operator ++(Object &a);
    friend Object operator ++(Object &a, int);
    friend Object operator +(const Object &a, const Object &b);
};

Object& operator =(Object &a, const Object &b) {
    a.count = b.count+1;
    return a;
}

istream& operator >>(istream &in, Object& a) {
    in>>a.count;
    return in;
}

ostream& operator <<(ostream &out, const Object& a) {
    out<<a.count;
    return out;
}

Object& operator ++(Object &a) {
    a.count++;
    return a;
}

Object operator ++(Object &a, int) {
    Object now(a.count);
    ++a;
    return now;
}

Object operator +(const Object &a, const Object &b) {
    return Object(a.count + b.count);
}

int main() {
    Object a, b;
    cin>>a>>b;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    a++;
    ++b;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    Object c = a+b;
    cout<<"a + b = "<<c<<endl;
    return 0;
}