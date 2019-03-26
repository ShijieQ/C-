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
const int maxn = 1e6+10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;

int A[maxn];
int Maxx[maxn], Minn[maxn];

struct node{
    int left;
    int right;
    int max;
    int sum;
    int min;
}Tree[maxn<<2];

void maintain(int root){
    int LC = root<<1; 
    int RC = (root<<1)+1;
    Tree[root].sum = Tree[LC].sum + Tree[RC].sum;   
    Tree[root].max = max(Tree[LC].max,Tree[RC].max);  
    Tree[root].min = min(Tree[LC].min,Tree[RC].min);  
}

void Build(int root,int start,int end){
    Tree[root].left = start;   
    Tree[root].right = end;
    if(start == end){
        Tree[root].sum = A[start];
        Tree[root].max = A[start];
        Tree[root].min = A[start];
        return;
    }
    int mid = (start + end)>>1;   
    Build(root<<1,start,mid);   
    Build((root<<1)+1,mid+1,end);  
    maintain(root);
}


void update(int root,int pos,int value){
    if(Tree[root].left == Tree[root].right && Tree[root].left == pos){
        Tree[root].sum += value;
        Tree[root].max += value;
        Tree[root].min += value;
        return;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1; 
    if(pos <= mid)   
        update(root<<1,pos,value);
    else
        update((root<<1)+1,pos,value);
    maintain(root);   
}


int Query(int root,int start,int end){
    if(start == Tree[root].left && Tree[root].right == end){
        return Tree[root].sum;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1;
    int ret = 0;
    if(end <= mid)
        ret += Query(root<<1,start,end);
    else if(start >= mid+1)
        ret += Query((root<<1)+1,start,end);
    else
    {
        ret += Query(root<<1,start,mid);
        ret += Query((root<<1)+1,mid+1,end);
    }
    return ret;
}


int RminQ(int root,int start,int end){
    if(start == Tree[root].left && Tree[root].right == end){
        return Tree[root].min;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1;
    int ret = INF;
    if(end <= mid)
        ret = min(ret,RminQ(root<<1,start,end));
    else if(start >= mid+1)
        ret = min(ret,RminQ((root<<1)+1,start,end));
    else{
        int a = RminQ(root<<1,start,mid);
        int b = RminQ((root<<1)+1,mid+1,end);
        ret = min(a,b);
    }
    return ret;
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
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
    }
    Build(1, 1, n);
    for(int i = 1; i <= n-k+1; i++){
        int l = i, r = i+k-1;
        Maxx[i] = RmaxQ(1, l, r);
        Minn[i] = RminQ(1, l, r);
    }
    cout<<Minn[1];
    for(int i = 2; i <= n-k+1; i++){
        cout<<" "<<Minn[i];
    }
    cout<<endl;
    cout<<Maxx[1];
    for(int i = 2; i <= n-k+1; i++){
        cout<<" "<<Maxx[i];
    }
    cout<<endl;
    return 0;
}