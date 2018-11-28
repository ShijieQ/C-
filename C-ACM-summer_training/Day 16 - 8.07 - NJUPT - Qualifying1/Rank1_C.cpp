#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

long long area(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
	long long int tem = x1*y2-x1*y3+x2*y3-x2*y1+x3*y1-x3*y2; //根据三点坐标求面积公式，我拆开了。 
	if(tem < 0)
		tem = -tem;
	return tem;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		long long int x1, y1, x2, y2, x3, y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
	//	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2, &x3, &y3);
	/*	double ans = area(x1, y1, x2, y2, x3, y3);
		if(ans<0)
			ans = -ans;
		if(ans == 0)
			cout<<0<<endl;
		else
			printf("%.2lf\n", ans);	*/
		if(area(x1, y1, x2, y2, x3, y3)%2){
			cout<<area(x1, y1, x2, y2, x3, y3)/2<<".50"<<endl;
		}	
		else
			cout<<area(x1, y1, x2, y2, x3, y3)/2<<".00"<<endl;
	}
} 
