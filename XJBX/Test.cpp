#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5

const int maxn = 2e5+10;

typedef int Status;
typedef int ElemType;
typedef struct ENode{
    int adjVex;             //任意顶点u相邻接的顶点
    ElemType w;             //边的权值
    struct ENode* nextArc;  //指向下一个边结点
}ENode;
typedef struct{
    int n;                  //图的当前顶点数
    int e;                  //图的当前边数
    ENode **a;              //指向一维数组
}LGraph;

Status Init(LGraph *lg,int nSize){
    int i;
    lg->n = nSize;
    lg->e = 0;
    lg->a = (ENode**)malloc(nSize*sizeof(ENode*));
    if(!lg->a)
        return ERROR;
    else{
        for(i = 0;i <lg->n;i++) lg->a[i] = NULL;
        return OK;
    }
}

void Destroy(LGraph *lg){
    int i;
    ENode *p,*q;
    for(i = 0;i <lg->n;i++){
        p = lg->a[i];
        q = p;
        while(p){
            p = p->nextArc;
            free(q);
            q = p;
        }
    }
    free(lg->a);
}

Status Exist(LGraph *lg,int u,int v){
    ENode *p;
    if(u < 0||v < 0||u >lg->n-1||v>lg->n-1||u==v)
        return ERROR;
    p = lg->a[u];
    while(p&&p->adjVex!=v) p = p->nextArc;
    if(!p) return ERROR;
    else return OK;
}

Status Insert(LGraph *lg,int u,int v,ElemType w)
{
    ENode* p;
    if(u < 0||v < 0||u > lg->n-1||v > lg->n-1||u==v) return ERROR;
    if(Exist(lg,u,v)) return Duplicate;
    p = (ENode *)malloc(sizeof(ENode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = lg->a[u];
    lg->a[u] = p;
    lg->e++;
    return OK;
}

Status Remove(LGraph *lg,int u,int v){
    ENode *p,*q;
    if(u < 0||v < 0||u >lg->n-1||v > lg->n-1||u==v)
        return ERROR;
    p = lg->a[u];q = NULL;
    while(p&&p->adjVex != v){
        q = p;
        p = p->nextArc;
    }
    if(!p) return NotPresent;
    if(q) q->nextArc = p->nextArc;
    else lg->a[u] = p->nextArc;
    free(p);
    lg->e--;
    return OK;
}

int Choose(int* d, int* s,int n)   //选出最小的d[i], i∈V-S
{
    int i,minpos;
    ElemType min;
    min=maxn;
    minpos=-1;
    for (i=1;i<n;i++)
        if (d[i]<min &&!s[i]){
            min=d[i];
            minpos=i;
        }
    return minpos; //返回下标位置
}

Status Dijkstra(int v, ElemType* d, int* path, LGraph *g)
{
    int i,k,w;
    int * s;
    if (v<0||v>g->n-1)     return ERROR;
    s=(int *)malloc(sizeof(int) * g->n);
    for (i=0;i<g->n;i++){
        s[i]=0;     //初始化
        ENode *p = g->a[v];
        if(!p){
            continue;
        }        
        ENode *q = p->nextArc;
        while(q && q->adjVex != i){
            d[i] = q->w;
            q = q->nextArc;
        }
        if (i!=v && d[i] < maxn)
            path[i]=v;
        else
            path[i]=-1;
    }
    s[v]=1; d[v]=0;   //顶点v 为源点
    for (i=1;i<g->n-1;i++) {
        k=Choose(d, s, g->n);
        s[k]=1;   //k 加入s 中
        printf("%d ",k);
        for (w=0; w<g->n; w++)    { //更新d 和path
            ENode *p = g->a[k];
            if(!p){
                continue;
            }
            ENode *q = p->nextArc;
            while(q && q->adjVex != w){
                if (!s[w] && d[k]+q->w < d[w]) {
                    d[w]=d[k]+q->w;
                    path[w]=k;
                }
                q = q->nextArc;
            }
        }
    }
    for (i=0;i<g->n;i++)
        printf("%d", d[i]);
    return OK;
}

int main(){
    LGraph lg;
    int n,e;
    cout << "输入图的顶点数、边数:"<<endl;
    cin >> n;
    cin >> e;
    int d[maxn],path[maxn];
    Init(&lg, n);
    cout << "输入各边及权值：" << endl;
    for(int i = 0;i < e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        Insert(&lg,u,v,w);
        }
    Dijkstra(0, d, path, &lg);
    return 0;
}