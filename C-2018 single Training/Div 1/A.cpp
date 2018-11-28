#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
char a;

int main(){
    /*
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    */
    int flag = 1;
    while((a = getchar()) != EOF){
        if(a == '"' && flag == 1){
            cout<<"``";
            flag = 2;
        }
        else if(a == '"' && flag == 2){
            cout<<"''";
            flag = 1;
        }
        else{
            cout<<a;
        }
    }
}
/*
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
*/
