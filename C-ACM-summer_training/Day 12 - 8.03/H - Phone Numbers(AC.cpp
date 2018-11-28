
#include<bits/stdc++.h>
using namespace std;
bool w[30];
int main()
{
	int n,k,i,j,l,r;
	string s;
	cin>>n>>k;
	cin>>s;
	for(i=0;i<s.size();i++)
		w[s[i]-'a'+1]=1;	    //保存字符 
	for(i=1;i<=26;i++)		    //找到集合中最小字符，l为其ASCII码 
		if(w[i]==1){
			l=i+'a'-1;
			break;
		}
	for(i=26;i>=1;i--)		    //找到集合中最大字符，r为其ASCII码 
		if(w[i]==1){
			r=i+'a'-1;
			break;
		}
	if(k>n){			    //第一种情况 
		cout<<s;   
		for(i=1;i<=k-n;i++)
			cout<<char(l);
		return 0;
	}
	for(i=k-1;i>=0;i--){
		if(r>s[i]){		    //如果有r大于s[i]，那么集合中肯定有字符大于s[i] 
			cout<<s.substr(0,i);//输出前面 
			for(j=s[i]-'a'+2;j<=26;j++){
				if(w[j]){    //找到第一个大于s[i]，的字符输出 
					cout<<char(j+'a'-1);
					break;
				}
			}
			for(j=i+1;j<k;j++)    //输出后面 
				cout<<char(l);
			return 0;
		}
	}
	return 0;
}
