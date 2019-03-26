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
char a[15];
int cnt = 1;
struct tree{
    int leng;
    tree *next[10];
    void init(){
        leng = 0;
        memset(next, NULL, sizeof(next));
    }
}tree[1<<16];
 
bool Insert(){
    bool flag = 0;
    struct tree *p = &tree[0], *q;
    int len = strlen(a);
    for(int i = 0; i < len; i++){
        int k = a[i] - '0';
        if(p->next[k] == NULL){
            q = &tree[cnt++];
            p->next[k] = q;
            flag = 1;
        }
        p = p->next[k];
        if(p->leng){
            return 0;
        }
    }
    p->leng = 1;
    return flag;
}

void destory(){
    for(int i = 1; i < cnt; i++){
        tree[i].init();
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        int flag = 1;
        cnt = 1;
        tree[0].init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%s", a);
            if(flag){
                flag = Insert();
            }
        }
        cout<<(flag ? "YES":"NO")<<endl;
        destory();
    }
    return 0;
}