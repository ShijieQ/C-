#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 35;
double p[15][maxn];

void init(){
    for(int i = 0; i <= 9; i++){
        for(int j = 1; j <= 30; j++){
            double a = log10(1 - pow(0.5, i+1));
            double b = (pow(2, j) - 1)*log10(2);
            p[i][j] = a+b;
        }
    }
}

double number(string s){
    double ans = 0;
    int i = 0;
    if(s.find('.', 0) != -1){
        while(s[i] != '.'){
            ans = ans*10 + s[i]-'0';
            i++;
        }
        int j = i++;
        while(i < s.length()){
            ans = ans + (s[i]-'0')*pow(10, -(i-j));
            i++;
        }
    }
    else{
        while(i < s.length()){
            ans = ans*10 + s[i]-'0';
            i++;
        }
    }
    return ans;
}

int main(){
    init();
    string s;
    while(cin>>s){
        if(s == "0e0"){
            break;
        }
        string a, b;
        int k = s.find('e', 0);
        a = s.substr(0, k);
        b = s.substr(k+1, s.length()-k);
        double A = number(a);
        int B = int(number(b));
        if(A >= 1){
            A /= 10;
            B++;
        }
        double t = log10(A) + B;
        for(int i = 0; i <= 9; i++){
            for(int j = 1; j <= 30; j++){
                if(fabs(t - p[i][j]) < 1e-5){
                    cout<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
    }
}