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
const int maxn = 2e5+10;
vector<char> vec;
char a[maxn];

int perzero(int i){
    int len = strlen(a);
    if(i) vec.push_back('-');//check -;
    while(i < len - 1 && a[i] == '0' && a[i+1] == '0'){
        i++;
    }
    if(i == len - 1){
        vec.push_back(a[i]);
        return NULL;
    }
    if(!(a[i+1] >= '0' && a[i+1] <= '9') || a[i] != '0'){
        vec.push_back(a[i]);
    }
    if(a[i+1] == '.' || a[i+1] == '/'){
        return i+1;
    }
    vec.push_back(a[++i]);
    i++;
    while(i < len && a[i] >= '0' && a[i] <= '9'){
        vec.push_back(a[i++]);
    }
    return i;
}

int main(){
    cin>>a;
    int len = strlen(a);
    reverse(a + (a[0] == '-'), a + len);
    perzero(a[0] == '-');
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}