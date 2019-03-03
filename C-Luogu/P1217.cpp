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
const int maxn = 1e5+10;
vector<int> vec;

bool check(int k){
    int len = sqrt(k);
    for(int i = 2; i <= len; i++){
        if(!(k%i)){
            return 0;
        }
    }
    return 1;
}

void init()
{
    for(int i = 1; i <= 9999; i++){
        int temp = i, temp2;
        int cnt = 0, k = 0;
        while(temp){
            k += temp%10;
            k *= 10;
            temp /= 10;
            cnt++;
        }
        k /= 10;
        temp = i;
        temp2 = i/10;
        for(int j = 1; j <= cnt; j++){
            temp *= 10;
            temp2 *= 10;
        }
        vec.push_back(temp + k);
        vec.push_back(temp2 + k);
    }
}

int main(){
    init();
    sort(vec.begin(), vec.end());
    int a, b;
    cin>>a>>b;
    for(int i = 0; i < vec.size() && vec[i] <= b; i++){
        if(vec[i] >= a && check(vec[i])){
            cout<<vec[i]<<endl;
        }
    }
    return 0;
}