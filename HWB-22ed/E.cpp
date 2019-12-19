#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
const int maxn = 1000;
const int mod = 1e9+7;

int main() {
	int T;
	cin>>T;
	while(T--) {
		pair<long long int, long long int> fir1, fir2;
		pair<long long int, long long int> sec1, sec2;
		cin>>fir1.x>>fir1.y>>fir2.x>>fir2.y;
		cin>>sec1.x>>sec1.y>>sec2.x>>sec2.y;
		if (fir1 >= sec1) {
			swap(fir1, sec1);
			swap(fir2, sec2);
		}
		long long int area = (fir2.x - fir1.x)*(fir2.y - fir1.y) + (sec2.x - sec1.x)*(sec2.y - sec1.y);
		if (fir2.x <= sec1.x || fir2.y <= sec1.y || fir1.y >= sec2.y || fir2.y <= sec1.y) {
			cout<<area<<endl;
		}
		else {
			long long int len = abs(min(fir2.y, sec2.y) - max(fir1.y, sec1.y));
			long long int len2 = abs(min(fir2.x, sec2.x) - max(fir1.x, sec1.x));
			cout<<area - len2*len<<endl;
		}
	}	
	return 0;
}