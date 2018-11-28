#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int LIS(int A[],int n)
{
    int* d = new int[n];
    int len = 1;
    int i,j;
    for(i=0;i<n;i++)
    {
        d[i]=1;
        for(j=0;j<i;j++)
        {
            if(A[j]<=A[i] && (d[j]+1)>=d[i])
                d[i]=d[j]+1;
        }
        if(d[i]>len) len=d[i];
    }
    delete []d;
    return len;
}
int main()
{
	int n;
	cin>>n;
	int arr[105];
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	cout<<LIS(arr, n)<<endl;
	return 0;
} 
