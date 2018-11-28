#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 16+10;
vector<int> vec[maxn];

void preOrderTransverse(int n){
    if(!n){
        return ;
    }
    else{
        cout<<n<<" ";
        preOrderTransverse(vec[n][0]);
        preOrderTransverse(vec[n][1]);
    }
}

void midOrderTransverse(int n){
    if(!n){
        return ;
    }
    else{
        midOrderTransverse(vec[n][0]);
        cout<<n<<" ";
        midOrderTransverse(vec[n][1]);
    }
}

void postOrderTransverse(int n){
    if(!n){
        return ;
    }
    else{
        postOrderTransverse(vec[n][0]);
        postOrderTransverse(vec[n][1]);
        cout<<n<<" ";
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int tema, temb;
        scanf("%d%d", &tema, &temb);
        vec[i].push_back(tema);
        vec[i].push_back(temb);
    }
    preOrderTransverse(1);
    cout<<endl;
    midOrderTransverse(1);
    cout<<endl;
    postOrderTransverse(1);
    cout<<endl;
    return 0;
}
/*
5
2 3
4 5
0 0
0 0
0 0
*/