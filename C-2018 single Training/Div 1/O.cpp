#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 0;

int main(){
    string a, b;
    while(cin>>a>>b){
        int i = 0, j = 0;
        int len_a = a.length();
        int len_b = b.length();
        while(i < len_a && j < len_b){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == len_a){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}