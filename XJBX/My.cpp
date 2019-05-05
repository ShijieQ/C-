#include<iostream>
#include<algorithm>
#include<vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int L = 3000,W = 1500;
double dp[3001][1501][2]={0};
vector<vector<double> > dp1(L+1,vector<double>(W+1,0));
int target[3001][1501][4] = {0};
int target1[3001][1501][4] = {0};
int wi[4][2]={{373,201},{477,282},{406,229},{311,225}};
vector<vector<double> > sx(4,vector<double>(L+1,0));
vector<vector<double> > sy(4,vector<double>(W+1,0));

int main()
{
	ofstream oFile;
	oFile.open("test.csv",ios::out|ios::trunc);
	cout<<"1";
	for(int i = 0;i <=3 ;i++)
	{
		for(int j = 1;j <= L;j++)
		{
			double tmp = 0;
			int a = j/wi[i][0];
			tmp = a*wi[i][1]*wi[i][0]/double(j*wi[i][1]);
			sx[i][j] = tmp;
	//		cout<<tmp<<" ";
		}
	}
	cout<<"2";
	//cout<<endl;
	for(int i = 0;i <=3 ;i++)
	{
		for(int j = 1;j <= W;j++)
		{
			double tmp = 0;
			int a = j/wi[i][1];
			tmp = a*wi[i][1]*wi[i][0]/double(j*wi[i][0]);
			sy[i][j] = tmp;
	//		cout<<tmp<<" ";
		}
	}
	cout<<"3";
	for(int i = 201;i <= L;i++)
	{
		for(int m = 0;m<=3;m++)
		{
			for(int j = 201; j<=W;j++)
			{ 
				if(j>=wi[m][1])
				{
					double value = ((dp[i][j-wi[m][1]][0])*(i*(j-wi[m][1]))+sx[m][i]*wi[m][1]*i)/double(i*j);
					if(value>dp[i][j][0])
					{
						dp[i][j][0] = value;
						for(int h = 0;h<=3;h++)
						{
							if(h == m)
								target[i][j][m] = target[i][j-wi[m][1]][m] ;
							else
								target[i][j][h] = target[i][j-wi[m][1]][h];	
						}
					}
				}
			}
		}
	}
	cout<<"4";
	for(int j = 1;j <= W;j++)
	{
		for(int m = 0;m <= 3;m++)
		{
			for(int i = 1;i <=L;i++)
			{
				if(i>=wi[m][1])
				{
					double value = ((dp1[i-wi[m][1]][j])*(j*(i-wi[m][1]))+(sy[m][j]*wi[m][1]*j))/double(i*j);
					if(value>dp1[i][j])
					{
						dp1[i][j]= value;
						for(int h = 0;h<=3;h++)
						{
							if(h == m)
								target1[i][j][m]= target1[i-wi[m][1]][j][m]+1;
							else
								target1[i][j][m]= target1[i-wi[m][1]][j][m];	
						}
					}
				}
			}
		}
	}
	for(int i = 1;i <= L;i++)
	{
		for(int j = 1;j <= W;j++)
		{
			if(dp[i][j][0]<dp1[i][j])
			{
				dp[i][j][0] = dp1[i][j];
				dp[i][j][1] = 1;
	
			}
			//cout<<dp[i][j]<<" ";	
		}
		//cout<<endl;
	}
	oFile<<"利用率"<<","<<"分割点x"<<","<<"分割点y"<<","<<"状态"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"状态"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"状态"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"状态"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"无"<<endl;
	
	vector<vector<double> >().swap(dp1);
	double ans[3001][3]={0};
	double ans1[1501][3]={0};
	for(int i = 1;i <= L;i++)
	{
		int flag=0;
		for( int j = 1;j <=W;j++)
		{
			double a = (dp[i][j][0]*i*j+dp[i][W-j][0]*(W-j)*i)/double(i*W);
			if(ans[i][0]<a)
			{
				ans[i][0] = a;
				flag = j;
			}
		}
		int flag1=0;
		for(int m = 1;m<=W;m++)
		{
			double b = (dp[L-i][m][0]*(L-i)*m+dp[L-i][W-m][0]*(W-m)*(L-i))/double((L-i)*W);
			if(ans[i][1]<b)
			{
				ans[i][1] = b;
				flag1 = m; 
			}
		}
		ans[i][2] = (ans[i][0]*i*W+ans[i][1]*(L-i)*W)/double(L*W);
		ans[i][0] = flag;
		ans[i][1] = flag1;
		cout<<"1";
		//oFile<<ans[i][2]<<","<<ans[i][0]<<","<<ans[i][1]<<","<<target[i][flag][0]*flag/wi[0][0]<<","<<target[i][flag][1]*flag/wi[1][0]<<","<<target[i][flag][2]*flag/wi[2][0]<<","<<target[i][flag][3]*flag/wi[3][0]<<","<<target[i][W-flag][0]*(W-flag)/wi[0][0]<<","<<target[i][W-flag][1]*(W-flag)/wi[1][0]<<","<<target[i][W-flag][2]*(W-flag)/wi[2][0]<<","<<target[i][W-flag][3]*(W-flag)/wi[3][0]<<","<<target[L-i][W-flag1][0]*(W-flag1)/wi[0][0]<<","<<target[L-i][W-flag1][1]*(W-flag1)/wi[1][0]<<","<<target[L-i][W-flag1][2]*(W-flag1)/wi[2][0]<<","<<target[L-i][W-flag1][3]*(W-flag1)/wi[3][0]<<","<<target[L-i][flag1][0]*(flag1)/wi[0][0]<<","
		//<<target[L-i][flag1][1]*(flag1)/wi[1][0]<<","<<target[L-i][flag1][2]*(flag1)/wi[2][0]<<","<<target[L-i][flag1][3]*(flag1)/wi[3][0]<<endl;
		oFile<<ans[i][2]<<","<<flag<<","<<flag1<<",";
		if(dp[i][flag][1] == 0)
		{
			oFile<<"0"<<","; 
			for(int c = 0;c<=3;c++)
				oFile<<target[i][flag][c]*(i/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[i][flag][c]*(flag/wi[c][0])<<",";
			}
		if(dp[i][W-flag][1] == 0)
		{
			oFile<<"0"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target[i][W-flag][c]*(i/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[i][W-flag][c]*((W-flag)/wi[c][0])<<",";
			}
		if(dp[L-i][flag1][1] == 0)
		{
			oFile<<"0"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target[L-i][flag1][c]*((L-i)/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[L-i][flag1][c]*(flag1/wi[c][0])<<",";
		}
		if(dp[L-i][W-flag1][1] == 0)
		{
			oFile<<"0"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target[L-i][W-flag1][c]*((L-i)/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[L-i][W-flag1][c]*((W-flag1)/wi[c][0])<<",";
		}
		oFile<<" "<<endl;
	}
	
	cout<<"kaishih"<<endl;
	oFile<<"利用率"<<","<<"分割点x"<<","<<"分割点y"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"p1"<<","<<"p2"<<","<<"p3"<<","<<"p4"<<","<<"无"<<endl; 	
	for(int j= 1;j <= W;j++)
	{
		int flag = 0;
		for(int i = 1;i<=L;i++)
		{
			double m = (dp[i][j][0]*i*j+dp[L-i][j][0]*(L-i)*j)/double(L*j);
			if(ans1[j][0]<m)
			{
				ans1[j][0] = m;
				flag = i;
			}
		}
		int flag1 = 0;
		for(int m = 1;m<=L;m++)
		{
			double b = (dp[m][W-j][0]*m*(W-j)+dp[L-m][W-j][0]*(L-m)*(W-j))/double(L*(W-j));
			if(ans1[j][1] < b)
			{
				ans1[j][1] = b;
				flag1 = m; 
			}
		}
		ans1[j][2] = (ans1[j][0]*L*j+ans1[j][1]*(W-j)*L)/double(L*W);
		ans1[j][0] = flag;
		ans1[j][1] = flag1;
		oFile<<ans1[j][2]<<","<<flag<<","<<flag1<<",";
		if(dp[flag][j][1] == 0)
		{
			oFile<<"0"<<","; 
			for(int c = 0;c<=3;c++)
				oFile<<target[flag][j][c]*(flag/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[flag][j][c]*(j/wi[c][0])<<",";
			}
		if(dp[L-flag][j][1] == 0)
		{
			oFile<<"0"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target[L-flag][j][c]*((L-flag)/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[L-flag][j][c]*(j/wi[c][0])<<",";
			}
		if(dp[flag1][W-j][1] == 0)
		{
			oFile<<"0"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target[flag1][W-j][c]*((flag1)/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[flag1][W-j][c]*((W-j)/wi[c][0])<<",";
		}
		if(dp[L-flag1][W-j][1] == 0)
		{
			oFile<<"0"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target[L-flag1][W-j][c]*((L-flag1)/wi[c][0])<<",";
		}
		else
		{
			oFile<<"1"<<",";
			for(int c = 0;c<=3;c++)
				oFile<<target1[L-flag1][W-j][c]*((W-j)/wi[c][0])<<",";
		}
		oFile<<" "<<endl;
	}
	//oFile.close(); 
	//cout<<tmp<<tmp1;
	return 0;
}