#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(char a, char b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n, k;
		cin>>n>>k;
		char a[11];
		char b[11];
		priority_queue <char,vector<char>,greater<char> > p_min;
		priority_queue <char,vector<char>,less<char> > p_max;
		int len;
		for(len = 0; n; len++){
			a[len] = n % 10;
			p_max.push(a[len]);
			p_min.push(a[len]);
			n /= 10;
		}
		for(int i = 0, j = len-1; i < len; i++)
			b[j--] = a[i];
		strcpy(a, b);
		char a_max[11], a_min[11];
		strcpy(a_max, a);
		strcpy(a_min, a);
		sort(a_max, a_max+len, cmp);
		sort(a_min, a_min+len);
		int flag_max = 0, flag_min = 0;
		for(int j = 0; j < k; j++){
			if(strcmp(a, a_min) == 0)
				break;
			for(int i = len-1; i >= j; i--){
//			for(int i = j; i < len; i++){
				if(a[i] == p_min.top()){
					swap(a[i], a[j]);
					break;
				}
			}
			p_min.pop();
		}
		for(int j = 0; j < k; j++){
			if(strcmp(b, a_max) == 0)
				break;
			for(int i = j; i < len; i++){
				if(b[i] == p_max.top()){
					swap(b[i], b[j]);
					break;
				}
			}
			p_max.pop();
		}
		for(int i = 0; i < len; i++)
			cout<<int (a[i]);
		cout<<" ";
		for(int i = 0; i < len; i++)
			cout<<int (b[i]);
		cout<<endl;
	}
}
