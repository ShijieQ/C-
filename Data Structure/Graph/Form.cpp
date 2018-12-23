#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define ERROR      0
#define OK         1
#define Overflow   2
#define Underflow  3
#define NotPresent 4
#define Duplicate  5

using namespace std;
const int maxn = 1000;
const int INF = 0x3f3f3f3f;
bool vis[maxn];
typedef int ElemType;
typedef int Status;

typedef struct eNode{
    int adjVex;
    ElemType w;
    struct eNode* nextArc;
} eNode;

typedef struct {
    int n;
    int e;
    eNode **a;
} lGraph;

Status Init(lGraph *lg, int nSize){
    lg->n = nSize;
    lg->e = 0;
    lg->a = (eNode **)malloc(nSize * sizeof(eNode*));
    if(!lg->a){
        return ERROR;
    }
    else{
        for(int i = 0; i < lg->n; i++){
            lg->a[i] = NULL;
        }
        return OK;
    }
}

void Destroy(lGraph *lg){
    eNode *p, *q;
    for(int i = 0; i < lg->n; i++){
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

Status Exist(lGraph *lg, int u, int v){
    if(u < 0 || v < 0 || u > lg->n-1 || v > lg->n-1 || u == v){
        return ERROR;
    }
    eNode *p = lg->a[u];
    while(p && p->adjVex != v){
        p = p->nextArc;
    }
    if(!p){
        return INF;
    }
    else{
        return p->w;
    }
}

Status Insert(lGraph *lg, int u, int v, ElemType w){
    if(u < 0 || v < 0 || u > lg->n-1 || v > lg->n-1 || u == v){
        return ERROR;
    }
    if(Exist(lg, u, v) != INF)
        return Duplicate;
    eNode *p = (eNode *)malloc(sizeof(eNode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = lg->a[u];
    lg->a[u] = p;
    lg->e++;
    return OK;
}

Status Remove(lGraph *lg, int u, int v){
    if(u < 0 || v < 0 || u > lg->n-1 || v > lg->n-1 || u == v){
        return ERROR;
    }
    eNode *p = lg->a[u];
    eNode *q = NULL;
    while(p && p->adjVex != v){
        q = p;
        p = p->nextArc;
    }
    if(!p){ 
        return NotPresent;
    }
    if(q){
        q->nextArc = p->nextArc;
    }
    else{
        lg->a[u] = p->nextArc;
    }
    free(p);
    lg->e--;
    return OK;
}

void DFS(lGraph lg, int k){
    vis[k] = 1;
    cout<<k<<"->";
    eNode *p = lg.a[k];
    while(p){
        if(!vis[p->adjVex]){
            DFS(lg, p->adjVex);
        }
        p = p->nextArc;
    }
}

void GraphDFS(lGraph lg){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < lg.n; i++){
        bool flag = 1;
        if(!vis[i]){
            DFS(lg, i);
            flag = 0;
        }
        if(!flag)
            cout<<"End"<<endl;
    }
    return ;
}

void BFS(lGraph lg, int k){
    vis[k] = 1;
    cout<<k<<"->";
    queue<ElemType> q;
    q.push(k);
    while(!q.empty()){
        ElemType temp = q.front();
        q.pop();
        eNode *p = lg.a[temp];
        while(p){
            if(!vis[p->adjVex]){
                vis[p->adjVex] = 1;
                cout<<p->adjVex<<"->";
                q.push(p->adjVex);
            }
            p = p->nextArc;
        }
    }
}

void GraphBFS(lGraph lg){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < lg.n; i++){
        bool flag = 1;
        if(!vis[i]){
            BFS(lg, i);
            flag = 0;
        }
        if(!flag)
            cout<<"End"<<endl;
    }
    return ;
}

void SearchShortPath(lGraph lg, int start){
    bool p[maxn][maxn];
    int D[maxn];
    for (int v = 0; v < lg.n; v++){
        vis[v] = 0; 
        D[v] = Exist(&lg, start, v);
        for (int w = 0; w < lg.n; w++){
            p[v][w] = 0;
        }
        if (D[v] < INF) {
            p[v][start] = 1; 
            p[v][v] = 1;
        }
    }
    D[start] = 0; 
    vis[start] = 0;
    for (int i = 1; i < lg.n; i++){
        int minn = INF;
        int v;
        for (int w = 0; w < lg.n; w++){
            if (!vis[w]){
                if (D[w] < minn) {
                    v = w; 
                    minn = D[w];
                }
            }
        }
        vis[v] = 1;
        for (int w = 0; w < lg.n; w++){
            int temp = Exist(&lg, v, w);
            if (!vis[w] && (minn + temp < D[w])){
                D[w] = minn + temp;
                p[w][w] = 1;
            }
        }
    }
    for(int i = 0; i < lg.n; i++){
        cout<<"D["<<i<<"] = "<<D[i]<<endl;
    }
}

int main(){
    lGraph lg;
    cout<<"Please input the maxSize of graph :";
    int Maxn;
    cin>>Maxn;
    Init(&lg, Maxn);
    cout<<"Please input the number of the edge inserted :";
    int n;
    cin>>n;
    cout<<"Please input the starting, ending and value of edge :"<<endl;
    for(int i = 0; i < n; i++){
        int l, r, v;
        cin>>l>>r>>v;
        Insert(&lg, l, r, v);
    }
    cout<<"The route of DFS is :"<<endl;
    GraphDFS(lg);
    cout<<"The route of BFS is :"<<endl;
    GraphBFS(lg);
    cout<<"Please input the node of starting:";
    int l;
    cin>>l;
    SearchShortPath(lg, l);
    return 0;
}