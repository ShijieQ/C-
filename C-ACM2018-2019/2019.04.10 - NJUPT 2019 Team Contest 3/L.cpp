#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define Online

const int maxn = 2000+100;
int w[maxn], d[maxn];
set<pair<int, int> > st;
vector<vector<pair<int, int> > > qr(2 * maxn);
vector<vector<int> > ans(maxn);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef Online
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
	int m, n, W, h; 
    cin>>m>>n>>W>>h;
	for(int i = 0; i < m; ++i){
		cin>>w[i];
		st.emplace(w[i], i);
	}
	for (int i = 0; i < n; ++i){
		cin>>d[i];
	}
	bool flag = false;
	for(int i = 0; i < n; ++i){
		for(auto& j : qr[i]){
			st.insert(j);
		}
		while(d[i] > 0 && !st.empty()){
			pair<int, int> p = *st.rbegin();
			st.erase(p);
			for (int j = 0; j < W; ++j){
				d[i + j]--;
			}
			ans[p.second].push_back(i);
			p.first -= W;
			if(p.first){
				qr[i + W + h].push_back(p);
            }
		}
		if(d[i] != 0){
			flag = true; 
            break;
		}
	}
	if(flag || !st.empty()){
        cout<<-1<<endl;
    }
	else{
		cout<<1<< endl;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < ans[i].size(); ++j){
				cout<<ans[i][j] + 1<<" ";
			}
            cout<<endl;
		}
	}
    return 0;
}