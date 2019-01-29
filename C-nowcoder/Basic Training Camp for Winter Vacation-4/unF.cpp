#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5+10;
//      DSU并查集
//      时间复杂度O(M Alpha(N), 这里Alpha是Ackerman函数的某个反函数, N为合并次数, M为查找次数
//      空间复杂度O(n)
const int INF = 0x3f3f3f3f;
int pre[maxn];//保存当前坐标的根节点
int Find(int x)//寻找根节点
{
    int r = x;
    while(pre[r] != r)
        r = pre[r];
    int i = x, j;
    while(i != r)//压缩路径
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void mix(int x, int y)//建立连接关系
{
	int fx = Find(x);
	int fy = Find(y);
	if(fx != fy)
    {
		pre[fx] = fy;
	}
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        mix(b, a);
        if(pre[a] != b){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}