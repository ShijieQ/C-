
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
		w[s[i]-'a'+1]=1;	    //�����ַ� 
	for(i=1;i<=26;i++)		    //�ҵ���������С�ַ���lΪ��ASCII�� 
		if(w[i]==1){
			l=i+'a'-1;
			break;
		}
	for(i=26;i>=1;i--)		    //�ҵ�����������ַ���rΪ��ASCII�� 
		if(w[i]==1){
			r=i+'a'-1;
			break;
		}
	if(k>n){			    //��һ����� 
		cout<<s;   
		for(i=1;i<=k-n;i++)
			cout<<char(l);
		return 0;
	}
	for(i=k-1;i>=0;i--){
		if(r>s[i]){		    //�����r����s[i]����ô�����п϶����ַ�����s[i] 
			cout<<s.substr(0,i);//���ǰ�� 
			for(j=s[i]-'a'+2;j<=26;j++){
				if(w[j]){    //�ҵ���һ������s[i]�����ַ���� 
					cout<<char(j+'a'-1);
					break;
				}
			}
			for(j=i+1;j<k;j++)    //������� 
				cout<<char(l);
			return 0;
		}
	}
	return 0;
}
