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
typedef struct tree{
    int leng;
    tree *next[10];
    tree(){
        leng = 0;
        memset(next, NULL, sizeof(next));
    }
}tree;
tree *root;
 
bool Insert(){
    bool flag = 0;
    tree *p = root;
    int len = strlen(a);
    for(int i = 0; i < len; i++){
        int k = a[i] - '0';
        if(p->next[k] == NULL){
            p->next[k] = new tree;
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

void destory(tree *p){
    if(p == NULL){
        return ;
    }
    for(int i = 0; i < 10; i++){
        if(p->next[i]){
            destory(p->next[i]);
        }
    }
    free(p);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        int flag = 1;
        root = new tree();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%s", a);
            if(flag){
                flag = Insert();
            }
        }
        cout<<(flag ? "YES":"NO")<<endl;
        destory(root);
    }
    return 0;
}