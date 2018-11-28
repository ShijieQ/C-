#include<algorithm>
#include<iostream>
#define ull unsign long long
#define ll long long
using namespace std;
ll n;
ll ans = 0;
int main(){
	cin>>n;
	ans = n;
	ll a2 = n/2;
	ll a3 = n/3;
	ll a5 = n/5;
	ll a7 = n/7;
	ans -= (a2+a3+a5+a7);
	ll a23 = n/(2*3);
	ll a25 = n/(2*5);
	ll a27 = n/(2*7);
	ll a35 = n/(3*5);
	ll a37 = n/(3*7);
	ll a57 = n/(5*7);
	ans += (a23+a25+a27+a35+a37+a57);
	ll a235 = n/(2*3*5);
	ll a237 = n/(2*3*7);
	ll a257 = n/(2*5*7);
	ll a357 = n/(3*5*7);
	ans -= (a235+a237+a257+a357);
	ll a2357 = n/(2*3*5*7);
	ans += a2357;
	cout<<ans<<endl;
	return 0;
} 
