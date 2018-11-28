/*
	二维数组，完全背包，且背包必须装满 
	*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#define INF 1e8
using namespace std;

int num[4][4005];

int main(){
	int v;
	int a[4];
	scanf("%d", &v);
	a[0] = 0;
	for(int i = 1; i <= 3; i++)	
		scanf("%d", &a[i]);
	for(int i = 0; i < 4; i++){ 
		for(int j = 0; j < 4005; j++){
			num[i][j] = -INF;
		}
	}
	for(int i = 0; i < 4; i++){
		num[i][0] = 0;
	}
	sort(a+1, a+4);
	for(int j = 1 ; j <= v ; j++){
		for(int i = 1 ; i <= 3 ; i++){ 
        	if(a[i]<=j){
				num[i][j] = max(num[i][j-a[i]] + 1, num[i-1][j]);
/*				for(int k = 0; k <= v; k++){
					cout<<num[i][k]<<" ";
				} 
				cout<<endl;*/ 
			}
        	else{
        		num[i][j] = num[i-1][j];
        	}
    	}
    }
	cout<<num[3][v]<<endl;

}
