#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,count = 0,j = 0;
	scanf("%d",&n);
	int *a = (int *)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++) 
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i = 0; i < n-1; i++)
	{
		if(!a[i]) continue;
		for(j = i+1; j < n; j++)
			if(a[i] == a[j])
			{
				a[j] = 0;
				count++;
			}
	}
	sort(a,a+n);
	printf("%d\n",n-count);
	for(int i = count; i < n-1; i++)
		printf("%d ",a[i]);
	printf("%d",a[n-1]);
	return 0;
 } 
