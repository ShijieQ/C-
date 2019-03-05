#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 100+10;

int main(){
    bool flag = 1;
    double x, s, a1 = 7, q = 0.98;
    cin>>s>>x;
    if(x >= s){
        flag = (x + s < a1); 
    }
    else{
        double n = ceil(log(1 - (s - x)*(1 - q)/a1)/log(q));
        double temp = pow(q, (int)(n));
        double len = a1*(1 - temp)/(1 - q);
        double esc;
        if(len <= s+x){
            esc = s + x - len;
            flag = (esc < a1*temp);
        }
    }
    cout<<(flag ? 'n':'y')<<endl;
    return 0;
}
