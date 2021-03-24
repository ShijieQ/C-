#include<iostream>

using namespace std;

int divide(int x, int y) {
    char ch = 'a';
    throw ch;
    if (y == 0) {
        throw y;
    }
    if (y < 0) {
        throw 1.0;
    }
    return x/y;
}

int main() {
    int a = 10, b = 0;
    try {
        // divide(a, b);
        divide(a, -1);
    }
    catch(int) {
        cout<<"except of divide zero"<<endl;
    }
    catch(double) {
        cout<<"except of divide negative"<<endl;
    }
    catch(...) {
        cout<<"all exception"<<endl;
    }
    cout<<"finished"<<endl;
    return 0;
}