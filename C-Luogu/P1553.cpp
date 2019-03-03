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
char a[maxn];
int pos = 0;
vector<char> vec;

bool check(){
    int len = strlen(a);
    for(int i = 0; i < len; i++){
        if(a[i] == '.' || a[i] == '/' || a[i] == '%'){
            pos = i;
            return 1;
        }
    }
    return 0;
}

int perzero(int i){
    int len = strlen(a);
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
    bool flag = check();
    int len = strlen(a);
    reverse(a, a+pos);
    reverse(a+pos+flag, a+len);
    int i = perzero(0);
    if(i < len && a[i] == '/'){
        vec.push_back(a[i]);
        perzero(i+1);
    }
    else if(i < len && a[i] == '.'){
        vec.push_back(a[i]);
        reverse(a+pos+flag, a+len);
        int l = vec.size();
        perzero(i+1);
        // for(int j = 0; j < vec.size(); j++){
        // cout<<vec[j];
        // }
        // cout<<endl;
        reverse(vec.begin() + l, vec.end());
    }
    else if(i < len && a[i] == '%'){
        vec.push_back(a[i]);
    }
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}
