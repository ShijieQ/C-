#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 6;
char a[maxn][maxn];
int x, y;

bool opera(char k){
    if(k == 'L'){
        if(y-1 < 0){
            return false;
        }
        swap(a[x][y], a[x][y-1]);
        y--;
    }
    if(k == 'R'){
        if(y+1 > 4){
            return false;
        }
        swap(a[x][y], a[x][y+1]);
        y++;
    }
    if(k == 'B'){
        if(x+1 > 4){
            return false;
        }
        swap(a[x][y], a[x+1][y]);
        x++;
    }
    if(k == 'A'){
        if(x-1 < 0){
            return false;
        }
        swap(a[x][y], a[x-1][y]);
        x--;
    }
    return true;
}

int main(){
    /*
    freopen("K.in", "r", stdin);
    freopen("K.out", "w", stdout);
    */
    int cas = 0;
    string s;
    getline(cin, s);
    while(s != "Z"){
        if(cas)
            cout<<endl;
        cout<<"Puzzle #"<< ++cas<<":"<<endl;
        bool flag = 1;
        for(int i = 0; i < 5; i++){
            a[0][i] = s[i];
            if(s[i] == ' '){
                x = 0;
                y = i;
            }
        }
        for(int i = 1; i <= 4; i++){
            getline(cin, s);
            for(int j = 0; j < 5; j++){
                a[i][j] = s[j];
                if(s[j] == ' '){
                    x = i;
                    y = j;
                }
            }
        }
        string k;
        getline(cin, k);
        while(1){
            int len = k.length();
            for(int i = 0; i < len; i++){
                if(!flag){
                    break;
                }
                flag = opera(k[i]);
            }
            if(k[len-1] == '0'){
                break;
            }
            else{
                getline(cin, k);
            }
        }
        if(!flag){
            cout<<"This puzzle has no final configuration."<<endl;
        }
        else{
            for(int i = 0; i < 5; i++){
                cout<<a[i][0];
                for(int j = 1; j < 5; j++){
                    cout<<" "<<a[i][j];
                }
                cout<<endl;
            }
        }
        getline(cin, s);
    }
}