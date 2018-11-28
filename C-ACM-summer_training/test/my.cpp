#include <stdio.h>
#include<iostream>
#include <string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int mod = 1e9+7;

int main(){
    long long int a = 2;
    for(int i = 1; i <= 1000; i++){
        printf("%lld  ", a);
        a = 2*a%mod;
    }
    system("pause");
}