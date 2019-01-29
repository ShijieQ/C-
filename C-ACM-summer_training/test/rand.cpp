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
    //while(T--){
        int t = 1 + rand()%30;
        cout<<t<<endl;
        while(t--){
            cout<< (rand()%50) + 2 <<" " <<(rand()%30) + 1 <<endl;
        }
    //}
    //system("pause");
}