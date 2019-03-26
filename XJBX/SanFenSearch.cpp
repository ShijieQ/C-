#include<iostream>

using namespace std;
int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int SanFen(int l, int r, int x){
    int m1 = (l + r)/2, m2 = (m1 + r)/2;
    if(x == a[m1]){
        return m1;
    }
    else if(x == a[m2]){
        return m2;
    }
    if(l == r - 1){
        return -1;
    }
    if(x < a[m1]){
        SanFen(l, m1, x);
    }
    else if(x > a[m1] && x < a[m2]){
        SanFen(m1, m2, x);
    }
    else if(x > a[m2]){
        SanFen(m2, r+1, x);
    }
}

int main(){
    for(int i = -2; i < 11; i++){
        cout<<"pos["<<i<<"] = "<<SanFen(0, 10, i)<<endl;
    }
    return 0;
}