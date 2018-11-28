#include<algorithm>
#include<iostream>
using namespace std;
int F[15000];
void init(){
	F[0] = 0;
	F[1] = 1;
	for(int i = 2; i <= 15000; i++)
		F[i] = (F[i-1]%10000 + F[i-2]%10000)%10000;
}
//long long int F[10000000];
/*
int a[105][3][3] = {0};
void init(){
	a[0][1][1] = 1;
	a[0][1][2] = 1;
	a[0][2][1] = 1;
	a[0][2][2] = 0;
	for(int i = 1; i <= 100; i++){
		a[i][1][1] = a[i-1][1][1] + a[i-1][2][1];
		a[i][1][2] = a[i-1][1][1];
		a[i][2][1] = a[i-1][1][1];
		a[i][2][2] = a[i-1][2][1];
	}
}

int cal(int a[3][3], int b[3][3], int k){
	int tem[3][3];
	for(int i = 0; i <= k; i++){
		tem[1][1] = (a[1][1]*b[1][1]%10000 + a[1][2]*b[2][1]%10000)%10000;
		tem[1][2] = (a[1][1]*b[1][2]%10000 + a[1][2]*b[2][2]%10000)%10000;
		tem[2][1] = (a[2][1]*b[1][1]%10000 + a[2][2]*b[1][2]%10000)%10000;
		tem[2][2] = (a[2][1]*b[1][2]%10000 + a[2][2]*b[2][2]%10000)%10000;
		a[1][1] = tem[1][1];
		a[1][2] = tem[1][2];
		a[2][1] = tem[2][1];
		a[2][2] = tem[2][2];
	}
	return a[1][2];
}
*/
int main(){
	ios::sync_with_stdio(false);
	init();
	int n;
	cin>>n;
	cout<<F[n%15000]<<endl;
	return 0;
}
