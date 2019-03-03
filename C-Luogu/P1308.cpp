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
const int maxn = 2e6+10;
char a[maxn], b[maxn];
char temp[maxn];
int cnt = 0;
int fir = -1;

bool check(){
    int len_a = strlen(a), len_temp = strlen(temp);
    if(len_a != len_temp){
        return false;
    }
    for(int i = 0; i < len_a; i++){
        if(!(a[i] == temp[i] || a[i] + 'a' - 'A' == temp[i] || a[i] == temp[i] + 'a' - 'A')){
            return false;
        }
    }
    return true;
}

void solve(){
    int len_a = strlen(a), len_b = strlen(b);
    int i = 0, j = 0;
    while(j < len_b){
        int k = 0;
        while(j < len_b && b[j] != ' '){
            temp[k++] = b[j++];
        }
        temp[k] = '\0';
        if(check()){
            cnt++;
            if(fir == -1){
                fir = j - len_a;
            }
        }
        j++;
    }
    if(!cnt){
        cout<<fir<<endl;
    }
    else{
        cout<<cnt<<" "<<fir<<endl;
    }
}

int main(){
    gets(a); 
    gets(b);
    solve();
    return 0;
}