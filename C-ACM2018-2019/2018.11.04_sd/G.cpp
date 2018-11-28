#include<bits/stdc++.h>
typedef long long ll ; 

using namespace std;

const double EXP = 1e-6;
const int maxn = 1e6+10;
char a1[110],a2[110];
int main(){
	scanf("%s%s",a1,a2);
	int len=strlen(a1);
	int cnt=0;
	for(int i=0;i<len;i++){
		if(a1[i]=='X'||a2[i]=='X')continue;
		a1[i]=a2[i]='X';
		bool flag=false;
		if(i-1>=0){
			if(a1[i-1]=='0') a1[i-1]='X',flag=true;
			else if(a2[i-1]=='0')a2[i-1]='X',flag=true;
		}
		if(i+1<len&&!flag){
			if(a1[i+1]=='0') a1[i+1]='X',flag=true;
			else if(a2[i+1]=='0') a2[i+1]='X',flag=true;
		}
		if(flag)cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
