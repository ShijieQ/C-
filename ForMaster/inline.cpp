#include<iostream>
#define defineMutiply(x, y) x*y

inline int inlindeMutiply(int x, int y) {
    return x*y;
}

using namespace std;

int main() {
    int define = defineMutiply(3+4, 2+3);
    int Inline = inlindeMutiply(3+4, 2+3);
    cout<<"define = "<<define<<endl; // define = 14
    cout<<"Inline = "<<Inline<<endl; // Inline = 35
    return 0;
}