#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    int T;
	cin>>T;
	while(T--){
		double a, b, x, y;
		cin>>a>>b>>x>>y;
		double single = atan(b/a);
		double l = (y + b*x/a)*sin(single) + (-x)/cos(single);
		double h = (y + b*x/a)*cos(single); 
		int ans = sqrt(l/h/tan(single))/2+0.5; 
		cout<<ans<<endl;
	} 
    return 0;
}
