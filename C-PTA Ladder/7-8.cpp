#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char str[100][19];
	int str_cmp[100][19];
	int n,sum;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>str[i];
	for(int i = 0; i < n; i++)
		str[i][18] = '1';
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 17; j++)
		{
			if(str[i][j] >= '0' && str[i][j] <= '9')
				str_cmp[i][j] = str[i][j] - '0';
			else
				str[i][18] = '0';
		}
		sum = str_cmp[i][0]*7 + str_cmp[i][1]*9 + str_cmp[i][2]*10 + str_cmp[i][3]*5 + str_cmp[i][4]*8 + str_cmp[i][5]*4 + str_cmp[i][6]*2 + str_cmp[i][7]*1 + str_cmp[i][8]*6 + str_cmp[i][9]*3 + str_cmp[i][10]*7 + str_cmp[i][11]*9 + str_cmp[i][12]*10 + str_cmp[i][13]*5 + str_cmp[i][14]*8 + str_cmp[i][15]*4 + str_cmp[i][16]*2;
		sum = sum % 11;
		if(sum == 0 && str[i][17] == '1') continue;
		if(sum == 1 && str[i][17] == '0') continue;
		if(sum == 2 && str[i][17] == 'X') continue;
		if(sum == 3 && str[i][17] == '9') continue;
		if(sum == 4 && str[i][17] == '8') continue;
		if(sum == 5 && str[i][17] == '7') continue;
		if(sum == 6 && str[i][17] == '6') continue;
		if(sum == 7 && str[i][17] == '5') continue;
		if(sum == 8 && str[i][17] == '4') continue;
		if(sum == 9 && str[i][17] == '3') continue;
		if(sum == 10 && str[i][17] == '2') continue;
		str[i][18] = '0';
	}
	int flag = 1;
	for(int i = 0; i < n; i++)
		if(str[i][18] == '0')
		{
			flag = 0;
			str[i][18] = '\0';
			printf("%s\n",str[i]);
		}
	if(flag) printf("All passed\n");
	return 0;
		
}
