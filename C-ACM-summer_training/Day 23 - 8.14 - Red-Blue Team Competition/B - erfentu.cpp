#include <iostream>  
#include <algorithm>  
#include <set>  
#include <map>  
#include <string.h>  
#include <queue>  
#include <sstream>  
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  

using namespace std;

int n, m, q;
int p[510][510];
int book[510];
int match[510];

int dfs(int u){
    for (int v = 1; v <= m; v++){
        if (book[v] == 0 && p[u][v] == 1){
            book[v] = 1;
            if (match[v] == 0 || dfs(match[v])){
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

char a[10], b[10];

struct node{
    int u, v;
}t1[510], t2[510];

int main(){
    int t;
    int cases = 1;
    scanf("%d", &t);
    while (t--){
        scanf("%d%d%d", &n, &m, &q);
        n = m = 0;
        memset(match, 0, sizeof(match));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= q; i++){
            scanf("%s %s",a,b);
            if (a[0] == 'M'){
                n++;
                sscanf(a, "%*c%d", &t1[n].u);
                sscanf(b, "%*c%d", &t1[n].v);
            }
            else{
                m++;
                sscanf(a, "%*c%d", &t2[m].u);
                sscanf(b, "%*c%d", &t2[m].v);
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1;j <= m;j++){
                if (t1[i].u == t2[j].v || t1[i].v == t2[j].u)
                    p[i][j] = 1;
            }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            memset(book, 0, sizeof(book));
            if (dfs(i))
                ans++;
        }
        printf("Case %d: %d\n", cases++, q - ans);
    }
    return 0;
}