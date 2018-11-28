#include<bits/stdc++.h>
int main()
{
	int T,i;
	int house[505][2];
	int h[3];
	scanf("%d",&T);
	while(T--)
	{
		int n,x,y;
		h[1]=10000;
		h[0]=-1; 
		scanf("%d %d %d",&n,&x,&y);
		for(i=1;i<=n;i++)
			scanf("%d %d",&house[i][0],&house[i][1]);
		for(i=1;i<=n;i++)
			if(house[i][0]<=x&&house[i][1]>=y)
				if(house[i][0]<h[1]||(house[i][0]==h[1]&&house[i][1]>h[2]))
				{
					h[0]=i;
					h[1]=house[i][0];
					h[2]=house[i][1];
				}
		printf("%d\n",h[0]);
	}
}
