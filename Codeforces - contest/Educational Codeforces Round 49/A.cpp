#include<iostream>
#include<algorithm>
#include<cstring>

const int maxn = 200;
const int INF = 0x3f3f3f3f;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string a, b;
        cin>>a;
        b = a;
        int flag = 1;
        reverse(b.begin(), b.end());
    //    cout<<a<<endl;
    //    cout<<b<<endl;
        for(int i = 0; i <= (n-1)/2; i++){
            if(flag == 0)
                break;
            if(a[i] == b[i])
                continue;
            else
                if(a[i] != 'a' && a[i] !='z'){
                    if(a[i] - b[i] == 2 || a[i] - b[i] == -2)
                        continue;
                    else   
                        flag = 0;
                }else if(a[i] == 'a'){
                    if(b[i] == 'c')
                        continue;
                    else
                        flag = 0;
                }else if(a[i] == 'z'){
                    if(b[i] == 'x')
                        continue;
                    else
                        flag = 0;
                }
        }
        if(flag)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
}