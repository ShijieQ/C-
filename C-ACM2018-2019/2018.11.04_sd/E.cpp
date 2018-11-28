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
bool judge(){//��Ȼ���Ƿ���������
    for(int i = 1; i < n; ++i){
        if(a[i - 1] > a[i]) return false;
    }
    return true;
}
int getCount(){//��̲���ȷ�����ָ���
    int cnt = 0;
    for(int i = 1; i < n; ++i){
        if(a[i - 1] + 1 != a[i]) ++cnt;
    }
    return cnt;
}
bool dfs(int deep){//��ǰ���
    if(3 * deep + getCount() > 3 * maxn) return false;//��֦
    if(judge()) return true;
    int save[15];//�ݴ�a����,���ڻָ�����a
    int cut[15];
    memcpy(save, a, sizeof(a));//save�ݴ�a
    for(int i = 0; i < n; ++i){//ö�ټ������
        if(!i || a[i - 1] + 1 != a[i]){//�������
            for(int j = i; j < n; ++j){//ö�ټ����յ�
                while(j + 1 < n && a[j] + 1 == a[j + 1]) ++j;//��ǰ��jΪ����������յ㣬���б�֤��Զ��Ҫ���ƻ���һ���Ѿ��������е�����Ƭ��
                memcpy(cut, save + i, sizeof (int) * (j - i + 1));//�����������cut��
                for(int k = j + 1; k < n; ++k){//ö��ճ�����
                    while(k + 1 < n && a[k] + 1 == a[k + 1]) ++k;//ճ����㱣֤���ƻ��������е�����Ƭ�Σ�kΪ���ȷ����ճ�����
                    memcpy(a + i, save + j + 1, sizeof(int) * (k - j));
                    memcpy(a + i + k - j, cut, sizeof(int) * (j - i + 1));//����������˽�����Ƭ��ճ�����±�k����
                    if(dfs(deep + 1)) return true;
                    memcpy(a, save, sizeof(a));//sizeof(a)������a��ռ�ڴ�ĳ���,���޸Ĳ��������ָ�����a
                }
            }//����������һ��һ�ε��������֣��������ֵĳ��ȿ�Ϊ1
        }
    }
    return false;//���м���ճ�������������
}
int solve(){
    if(judge()) return 0;//����Ҫ����ճ��
    for(maxn = 1; ; ++maxn){//ö�����
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
