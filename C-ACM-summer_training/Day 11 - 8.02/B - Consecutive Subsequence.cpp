#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
 
const int maxn =300003,INF=0x7f7f7f7f;
int low[maxn],a[maxn];
int n,ans;
int next[maxn];

struct node{
	int pos;
	int k;
}a1[maxn];

int binary_search(int *a,int r,int x) 
{
    int l=1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]<=x)
            l=mid+1;
        else 
            r=mid-1;
    }
    while(a[l+1]==a[l])
    	l++;
    return l;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        a1[i].k = a[i];
		a1[i].pos = i;
        low[i]=INF;//����low�д������Сֵ������low��ʼ��ΪINF 
    }
    low[1]=a[1]; 
    next[1]=a1[1].pos;
    ans=1;//��ʼʱLIS����Ϊ1 
    for(int i=2;i<=n;i++)
    {
        if(a[i]==low[ans]+1){
            low[++ans]=a[i];
            next[ans] = a1[i].pos;
        }
        else if(a[i] == low[ans]){
        	low[ans]=a[i];
            next[ans] = a1[i].pos;
		}
        else{ //�����ҵ�low�е�һ��>=a[i]��λ��low[j]����a[i]����low[j] 
        	int po = binary_search(low,ans,a[i]);
            low[po] = a[i];
            next[po] = a1[i].pos;
        }
    }
    cout<<ans<<endl;
    for(int i = 1; i <= ans; i++)
		cout<<next[i]<<" ";
	cout<<endl; 
    return 0;
}
