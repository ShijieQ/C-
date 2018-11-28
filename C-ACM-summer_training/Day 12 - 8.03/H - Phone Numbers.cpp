#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<cstdio>
using namespace std;

void print(int l, int n, char *a){
	if(n <= l)	return;
	else
		for(int i = l; i < n; i++)
			cout<<a[i];
}

char Find(char *a, char b, int n){
	for(int i = 0; i < n; i++){
		if(a[i] > b)
			return a[i];
	}
}
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	char s[100005];
	char s1[100005];
	scanf("%s", s);
	int len = strlen(s);
	set<char> a;
	for(int i = 0; i < len; i++){
		a.insert(s[i]);
	}
	set<char>::iterator iter;
	int z = 0;
	for(iter = a.begin(); iter != a.end(); iter++)
		s1[z++] = *iter;
	char ch_fir = s1[0];
	char ch_end = s1[strlen(s1)-1];
	if(k > n){
		cout<<s;
		for(int i = k; k > n; k--){
			cout<<ch_fir;
		}
		cout<<endl;
	}
	else{
		int i;
		for(i = k-1; i >= 0; i--){
			if(s[i] < ch_end){
			//	cout<<s[i]<<endl;
				print(0, i, s);
				break;
			}
		}
		cout<<Find(s1, s[i], strlen(s1));
		for(int j = i+1; j < k; j++)
			cout<<ch_fir;
	}
}
