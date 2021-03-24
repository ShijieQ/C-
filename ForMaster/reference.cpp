#include<iostream> 

using namespace std;

int main() {
    // int a[10];
    // int& *b = a; // Error
    int a = 0;
    int const &b = a;
    // b++; Error
    // cout<<"a.Address: "<<a<<", b.address: "<<b<<endl;
    return 0;
}