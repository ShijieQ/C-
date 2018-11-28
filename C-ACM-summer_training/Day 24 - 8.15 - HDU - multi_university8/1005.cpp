#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n;
        char a[4][4];
        cin>>n;
        for(int i = 0; i < 3; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= n; i++){
            char s[3];
            cin>>s;
            int x, y;
            if(s[0] == '1'){
                x = 0;
                y = 0;
            }
            else if(s[0] == '2'){
                x = 0;
                y = 1;
            }
            else if(s[0] == '3'){
                x = 1;
                y = 0;
            }
            else{
                x = 1;
                y = 1;
            }
            if(s[1] == 'C'){
                char temp;
                temp = a[x][y];
                a[x][y] = a[x+1][y];
                a[x+1][y] = a[x+1][y+1];
                a[x+1][y+1] = a[x][y+1];
                a[x][y+1] = temp;
            }
            else{
                char temp;
                temp = a[x][y];
                a[x][y] = a[x][y+1];
                a[x][y+1] = a[x+1][y+1];
                a[x+1][y+1] = a[x+1][y];
                a[x+1][y] = temp;
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}