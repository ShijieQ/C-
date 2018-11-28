#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

double f(double x){
    double y = cos(x);
    return tan(sin(x))-sin(tan(x))+y*y*y*y*y-0.5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, b;
    int nb;
    while(cin >> a >> b >> nb){
        int ans = 0;
        double in = (b-a)/nb;
        for(int i = 0; i < nb; i++)
        {
            if(f(a+i*in)*f(a+(i+1)*in) < 0)    
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}