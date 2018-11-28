#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<windows.h>
#include<time.h>
#define maxn 10
using namespace std;
const int INF = 30000;

int main(){
    //int T = maxn;
    srand((int)time(NULL));
   // while(T--){
        int t = 1 + rand()%200;
        cout<<t<<endl;
        while(t--){
            cout<< 1000*(rand()%10000) <<" " <<1000*(rand()%10000) <<endl;
        }
    // }
    system("pause");
}