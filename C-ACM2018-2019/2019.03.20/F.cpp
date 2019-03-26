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

const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const int MAX = 5e4+10;
const int maxn = 2e5+100;
int A[maxn];

struct node{
    int left;
    int right;
    int max;
}Tree[maxn<<2];

void maintain(int root){
    int LC = root<<1; 
    int RC = (root<<1)+1;  
    Tree[root].max = max(Tree[LC].max,Tree[RC].max);    
}

void Build(int root,int start,int end){
    Tree[root].left = start;   
    Tree[root].right = end;
    if(start == end){
        Tree[root].max = A[start];
        return;
    }
    int mid = (start + end)>>1;   
    Build(root<<1,start,mid);   
    Build((root<<1)+1,mid+1,end);  
    maintain(root);
}


void update(int root,int pos,int value){
    if(Tree[root].left == Tree[root].right && Tree[root].left == pos){
        Tree[root].max += value;
        return;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1; 
    if(pos <= mid)   
        update(root<<1,pos,value);
    else
        update((root<<1)+1,pos,value);
    maintain(root);   
}


int RmaxQ(int root,int start,int end){
    if(start == Tree[root].left && Tree[root].right == end)
    {
        return Tree[root].max;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1;
    int ret = -INF;
    if(end <= mid)
        ret = max(ret,RmaxQ(root<<1,start,end));
    else if(start >= mid+1)
        ret = max(ret,RmaxQ((root<<1)+1,start,end));
    else
    {
        int a = RmaxQ(root<<1,start,mid);
        int b = RmaxQ((root<<1)+1,mid+1,end);
        ret = max(a,b);
    }
    return ret;
}

int main(){
    int n, t, c;
    scanf("%d%d%d", &n, &t, &c);
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
    }
    Build(1, 1, n);
    int cnt = 0;
    for(int i = 1; i <= n-c+1; i++){
        if(RmaxQ(1, i, i+c-1) <= t){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}