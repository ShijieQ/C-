#include<iostream>

using namespace std;

int main() {
    int x = 0;
    const int* p = &x;
    cout<<"*p = "<<*p<<endl;

    // change x
    x = 1;
    cout<<"*p = "<<*p<<endl;

    // change p
    int y = 10;
    p = &y;
    cout<<"*p = "<<*p<<endl;

    //change *p
    // (*p)++;
    // cout<<"*p = "<<*p<<endl; Error

//----------------------------------------------------

    int* const q = &x;
    cout<<"*q = "<<*q<<endl;

    // change x
    x = 2;
    cout<<"*q = "<<*q<<endl;

    // change q
    // int k = 10;
    // q = &q;
    // cout<<"*q = "<<*q<<endl; Error

    // change *q
    (*q)++;
    cout<<"*q = "<<*q<<endl;

//----------------------------------------------------

    const int* const r = &x;
    cout<<"*r = "<<*r<<endl;

    // change x
    x = 3;
    cout<<"*r = "<<*r<<endl;

    // change r
    // int l = 2;
    // r = &l;
    // cout<<"*r = "<<*r<<endl; Error

    // change *r
    // (*r)++;
    // cout<<"*r = "<<*r<<endl; Error

    return 0;
}