#include<algorithm>
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	char a[1005];
	scanf("%s", a);
	sort(a, a+n);
	int ans = 0;
	char ch;
	for(int j = 1; j <= n; j++){
		int tem;
		for(tem = 0; tem < n; tem++)
			if(a[tem] != '0')
				break;
		ch = a[tem];
		a[tem] = '0';
		if(tem == n)
			break;
		for(int i = tem+1; i < n; i++){
			if(a[i] == ch+1){
				ch = a[i];
				a[i] = '0';
			}
		}
		ans++;
	}
	cout<<ans<<endl;
}

    
