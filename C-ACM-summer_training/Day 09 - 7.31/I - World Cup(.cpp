/*AC´úÂë
	*/ 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long int a[100005];
//long long int step[100005];
int main(){
	int n;
	cin>>n;
	long long int f;
	long long int k;
	long long int step = 0;
	long long int min = 100000000000;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] <= i-1){
			cout<<i<<endl;
			return 0;
		}
//		int k = a[i]-i+1;
/*		if(k < 0){
			k = 0;
			step = 1LL*((k/n+1)*n);
        }
        else*/
//        step = 1LL*((k/n+1)*n)+i-1;
		if((a[i]-(i-1))%n)
			k = ((a[i]-(i-1))/n)+1;
		else
			k = (a[i]-(i-1))/n;
//		int k = (a[i]-(i-1))%n?((a[i]-(i-1))/n)+1:((a[i]-(i-1))/n);
//		cout<<i<<" : "<<step<<":" <<k<<" :"<<(k/n+1)*n<<endl;
//		step[i] = (a[i]/n+1)*n + i - 1;
		f = k*n+i;
		if(f < min)
			min = f;
	}
	if(min%n == 0)
		cout<<n<<endl;
	else
		cout<<min%n<<endl;
}
