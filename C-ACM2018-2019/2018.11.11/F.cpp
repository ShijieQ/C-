#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 3e5+10;
int ans = 0, now = 0;
int r[maxn];

struct node{
	vector<int> v;
	int l;
	void push(int t){
		v.push_back(t);
	}
	void read(int t){
		while(l < v.size() && v[l] <= t) 
            l++;
	}
	void readall(){
		for(int i = l;i < v.size(); i++){
            if(r[v[i]] == 0){ 
                ans--;
                r[v[i]] = 1;
            }
        }
		l = v.size();
	}
}x[maxn];

int main(){
    int n, q;
	scanf("%d%d",&n,&q); 
    int k = 0;
	for(int i = 1; i <= q; i++){
		int temp1, temp2; 
        scanf("%d%d",&temp1,&temp2);
		if(temp1 == 1){
			x[temp2].push(++k); 
            ans++;
		}
        else if(temp1 == 2){
			x[temp2].readall();
		}
        else{
			for(int j = now + 1; j <= temp2; j++)
				if(!r[j]){
					ans--; 
                    r[j] = 1;
				}
			now = max(now, temp2);
		}
		printf("%d\n", ans);
	}
}