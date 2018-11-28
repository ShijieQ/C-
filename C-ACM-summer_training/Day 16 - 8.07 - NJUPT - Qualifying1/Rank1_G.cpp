#include<algorithm>
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	n--;
	queue<int> q;
	q.push(0);
	for(int i = 0; i < n; i++){
		int len = q.size();
		q.push(1);
		for(int j = 1; j <= len; j++){
			int tem = q.front();
			q.pop();
			q.push(tem);
			q.push((j+1)%2);
		}
	}
	int a[20000];
	int k = 0;
	while(!q.empty()){
		a[k++] = q.front();
		q.pop();
	}
	for(int i = k-1; i >=0; i--){
		cout<<a[i];
	}
	cout<<endl;
}
/*
       0         1
   0   0   1     1+2
 0 0 1 0 0 1 1   1+2+4
001001100011011  1+2+4+8
0010011000110110001001110011011
00100100
*/
