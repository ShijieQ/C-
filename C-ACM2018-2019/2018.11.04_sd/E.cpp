#pragma comment(linker, "/STACK:102400000, 102400000")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<list>
#define Min(a, b) ((a < b) ? a : b)
#define Max(a, b) ((a < b) ? b : a)
typedef long long ll;
typedef unsigned long long llu;
const int INT_INF = 0x3f3f3f3f;
const int INT_M_INF = 0x7f7f7f7f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const ll LL_M_INF = 0x7f7f7f7f7f7f7f7f;
const int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 1e5 + 10;
const int MAXT = 10000 + 10;
using namespace std;
int a[15];
int maxn;
int n;
bool judge(){//自然段是否有序排列
    for(int i = 1; i < n; ++i){
        if(a[i - 1] > a[i]) return false;
    }
    return true;
}
int getCount(){//后继不正确的数字个数
    int cnt = 0;
    for(int i = 1; i < n; ++i){
        if(a[i - 1] + 1 != a[i]) ++cnt;
    }
    return cnt;
}
bool dfs(int deep){//当前深度
    if(3 * deep + getCount() > 3 * maxn) return false;//剪枝
    if(judge()) return true;
    int save[15];//暂存a数组,便于恢复数组a
    int cut[15];
    memcpy(save, a, sizeof(a));//save暂存a
    for(int i = 0; i < n; ++i){//枚举剪切起点
        if(!i || a[i - 1] + 1 != a[i]){//剪切起点
            for(int j = i; j < n; ++j){//枚举剪切终点
                while(j + 1 < n && a[j] + 1 == a[j + 1]) ++j;//当前的j为剪切区间的终点，剪切保证永远不要“破坏”一个已经连续排列的数字片段
                memcpy(cut, save + i, sizeof (int) * (j - i + 1));//剪切区间放在cut里
                for(int k = j + 1; k < n; ++k){//枚举粘贴起点
                    while(k + 1 < n && a[k] + 1 == a[k + 1]) ++k;//粘贴起点保证不破坏连续排列的数字片段，k为最后确定的粘贴起点
                    memcpy(a + i, save + j + 1, sizeof(int) * (k - j));
                    memcpy(a + i + k - j, cut, sizeof(int) * (j - i + 1));//这两步完成了将剪切片段粘贴到下标k后面
                    if(dfs(deep + 1)) return true;
                    memcpy(a, save, sizeof(a));//sizeof(a)是数组a所占内存的长度,该修改不成立，恢复数组a
                }
            }//剪切区间是一段一段的连续数字，连续数字的长度可为1
        }
    }
    return false;//所有剪切粘贴情况都不成立
}
int solve(){
    if(judge()) return 0;//不需要剪切粘贴
    for(maxn = 1; ; ++maxn){//枚举深度
        if(dfs(0)) return maxn;
    }
}
int main(){
    int kase = 0;
    while(scanf("%d", &n) == 1){
        if(!n) return 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
        }
        int ans = solve();
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
