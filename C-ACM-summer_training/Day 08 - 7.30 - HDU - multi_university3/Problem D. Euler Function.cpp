//b17041222
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define Max 1000005
//long long int euler[Max];
int main(){
/*    euler[1]=1;
    for(int i=2;i<Max;i++)
       euler[i]=i;
    for(int i=2;i<Max;i++)
    	if(euler[i]==i)
           for(int j=i;j<Max;j+=i)
              euler[j]=euler[j]/i*(i-1);

	for(int i = 0; i < Max; i++){
		cout<<euler[i]<<" ";
		if(i%10 == 0)
			cout<<endl;
	}*/
	int n;
	cin>>n; 
	while(n--){
		int temp;
		scanf("%d", &temp);
		if(temp == 1)
			cout<<5<<endl;
		if(temp >= 2)
			cout<<5+temp<<endl;
	}
	return 0;
}
