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
bool vis[maxn];
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType **a;            //邻接矩阵
    int n;                   //顶点个数
    int e;                   //当前边数
    ElemType noEdge;         //两顶点间无边时的值
} mGraph;

Status Init(mGraph *mg, int nSize, ElemType noEdgeValue){
    mg->n = nSize;
    mg->e = 0;
    mg->noEdge = noEdgeValue;
    mg->a = (ElemType **)malloc(nSize * sizeof(ElemType*));
    if(!mg->a){
        return ERROR;
    }
    for(int i = 0; i < mg->n; i++){
        mg->a[i] = (ElemType* )malloc(nSize * sizeof(ElemType));
        for(int j = 0; j < mg->n; j++){
            mg->a[i][j] = mg->noEdge;
        }
        mg->a[i][i] = 0;
    }
    return OK;
}

void Destroy(mGraph *mg){
    for(int i = 0; i < mg->n; i++){
        free(mg->a[i]);
    }
    free(mg->a);
    return ;
}

Status Exist(mGraph *mg, int u, int v){
    if(u < 0 || v < 0|| u > mg->n-1 || v > mg->n-1 || u == v || mg->a[u][v] == mg->noEdge){
        return ERROR;
    }
    return OK;
}

Status Insert(mGraph *mg, int u, int v, ElemType w){
    if(u < 0 || v < 0 || u > mg->n-1 || v > mg->n-1 || u == v){
        return ERROR;
    }
    if(mg->a[u][v] != mg->noEdge){
        return Duplicate;
    }
    mg->a[u][v] = w;
    mg->e++;
    return OK;
}

Status Remove(mGraph *mg, int u, int v){
    if(u < 0 || v < 0 || u > mg->n-1 || v > mg->n-1 || u == v){
        return ERROR;
    }
    if(mg->a[u][v] == mg->noEdge){
        return NotPresent;
    }
    mg->a[u][v] = mg->noEdge;
    mg->e--;
    return OK;
}

void DFS(mGraph mg, int k){
    vis[k] = 1;
    cout<<k<<"->";
    for(int i = 0; i < mg.n; i++){
        if(mg.a[k][i] != mg.noEdge && !vis[i]){
            DFS(mg, i);
        }
    }
}

void GraphDFS(mGraph mg){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < mg.n; i++){
        bool flag = 1;
        if(!vis[i]){
            DFS(mg, i);
            flag = 0;
        }
        if(!flag)
            cout<<"End"<<endl;
    }
    return ;
}

void BFS(mGraph mg, int k){
    vis[k] = 1;
    cout<<k<<"->";
    queue<ElemType> q;
    q.push(k);
    while(!q.empty()){
        ElemType temp = q.front();
        q.pop();
        for(int i = 0; i < mg.n; i++){
            if(mg.a[temp][i] != mg.noEdge && !vis[i]){
                vis[i] = 1;
                cout<<i<<"->";
                q.push(i);
            }
        }
    }
}

void GraphBFS(mGraph mg){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < mg.n; i++){
        bool flag = 1;
        if(!vis[i]){
            BFS(mg, i);
            flag = 0;
        }
        if(!flag)
            cout<<"End"<<endl;
    }
    return ;
}

int main(){
    mGraph mg;
    cout<<"Please input the maxSize of graph :";
    int Maxn;
    cin>>Maxn;
    cout<<"Please input the value of the noEdge :";
    int noEdge;
    cin>>noEdge;
    Init(&mg, Maxn, noEdge);
    cout<<"Please input the number of the edge inserted :";
    int n;
    cin>>n;
    cout<<"Please input the starting, ending and value of edge :"<<endl;
    for(int i = 0; i < n; i++){
        int l, r, v;
        cin>>l>>r>>v;
        Insert(&mg, l, r, v);
    }
    cout<<"The route of DFS is :"<<endl;
    GraphDFS(mg);
    cout<<"The route of BFS is :"<<endl;
    GraphBFS(mg);
    return 0;
}