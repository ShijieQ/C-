#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

typedef struct fact{
	int start;
	int end;
}fact;

bool cmp(struct fact a, struct fact b)
{
	if(a.start < b.start)
		return true;
	else if(a.start > b.start)
		return false;
	else
		return a.end > b.end;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		int arr[100005];
		fact facts[100005];
		for(int i = 0; i < m; i++)
			arr[i] = 1;
		for(int i = 0; i < n; i++)
			scanf("%d %d", &facts[i].start, &facts[i].end);
		sort(facts, facts+n, cmp);
		
		/*
		for(int i = 0; i < n; i++)
			cout<<facts[i].start<<" "<<facts[i].end<<endl;
		*/
		
		int k = 0;
		for(int i = facts[0].start-1; i < facts[0].end; i++)
			arr[i] = ++k;
		k = 0;
		for(int i = 1; i < n; i++)
		{
			if(facts[i-1].end >= facts[i].start)
			{
				for(int j = facts[i-1].end; j < facts[i].end; j++)
					arr[j] = ++k;
				k = 0;
			}
			else
			{
				for(int j = facts[i].start-1; j < facts[i].end; j++)
					arr[j] = ++k;
				k = 0;
			}
		}
		if(T)
		{
			cout<<arr[0];
			for(int i = 1; i < m; i++)
				cout<<" "<<arr[i];
			cout<<endl;
		}
		else
		{
			cout<<arr[0];
			for(int i = 1; i < m; i++)
				cout<<" "<<arr[i];
		}
	}
} 
/*
 5 3
 1 4
 2 3
 4 5
 */
  
 /*
 1 4
 2 8
 12341567
 */
