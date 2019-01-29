#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool judge(string str)
{
    int len = str.length();
    for(int i = 0; i < len/2; i++){
        if(str[i] != str[len-1-i])
            return false;
    }
    return true;
}

int main(){
    string str;
    cin>>str;
    bool flag = false;
    int i;
    int len = str.length();
    for(i = 0; i < len/2;i++){
        if(str[i] != str[len-1-i])
            break;;
    }
    if(i == len/2)
        flag = true;
    else
        flag = (judge(str.substr(i+1, len - 2*i - 1)) || judge(str.substr(i, len- 2*i -1)));
    cout<< (flag ? "Yes" : "No")<<endl;
    return 0;
}