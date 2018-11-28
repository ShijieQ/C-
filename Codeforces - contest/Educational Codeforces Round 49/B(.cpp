#include<iostream>
#include<algorithm>
#include<cstring>

const int maxn = 100000+5;
const int INF = 0x3f3f3f3f;
using namespace std;

int main(){
    long long d, q;
    cin>>d>>q;
    while(q--){
        long long m, n;
        cin>>m>>n;
        if(d%2 == 0){
            if((m+n)%2 == 0){
                if(m%2 == 0)
                    cout<<(m-1)*(d/2)+n/2<<endl;
                else    
                    cout<<(m-1)*(d/2)+(n+1)/2<<endl;
            }else{
                if(m%2 == 0)
                    cout<<(m-1)*(d/2)+(n+1)/2+d*d/2<<endl;
                else    
                    cout<<(m-1)*(d/2)+n/2+d*d/2<<endl;
            }
        }else{
            if((m+n)%2 == 0){
                if(m%2 == 0)
                    cout<<(m/2)*((d+1)/2)+(m-(m/2)-1)*(d/2)+n/2<<endl;
                else
                    cout<<(m/2)*((d+1)/2)+(m-(m/2)-1)*(d/2)+(n+1)/2<<endl;
            }else{
                if(m%2 == 0)
                    cout<<(m/2)*((d+1)/2)+(m-(m/2)-1)*(d/2)+(n+1)/2+d*d/2<<endl;
                else
                    cout<<(m/2)*((d+1)/2)+(m-(m/2)-1)*(d/2)+n/2+d*d/2+1<<endl;
            }
        }
    }
}