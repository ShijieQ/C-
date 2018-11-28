#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 12;
pair<int, string> p[maxn*maxn];

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    /*
    freopen("L.in", "r", stdin);
    freopen("L.out", "w", stdout);
    */
    int r, c, cas = 0;
    while(cin>>r && r){
        cin>>c;
        string s;
        char a[maxn][maxn];
        int id[maxn][maxn];
        getchar();
        memset(id, 0, sizeof(id));
        for(int i = 0; i < r; i++){
            getline(cin, s);
            for(int j = 0; j < c; j++){
                a[i][j] = s[j];
            }
        }
        int num = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(a[i][j] != '*' && (i == 0 || j == 0 || a[i-1][j] == '*' || a[i][j-1] == '*')){
                    id[i][j] = ++num;
                }
            }
        }
        /*
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                printf("%4d", id[i][j]);
            }
            cout<<endl;
        }
        */
        if(cas)
            cout<<endl;
        cout<<"puzzle #"<< ++cas <<":"<<endl;
        cout<<"Across"<<endl;
        for(int i = 0; i < r; i++){
            int j = 0;
            while(j < c){
                while(id[i][j] == 0 && j < c){
                    j++;
                }
                if(j == c){
                    continue;
                }
                else{
                    printf("%3d.", id[i][j]);
                    while(a[i][j] != '*' && j < c){
                        cout<<a[i][j];
                        j++;
                    }
                    cout<<endl;
                }
            }
        }
        int k = 0;
        cout<<"Down"<<endl;
        for(int i = 0; i < c; i++){
            int j = 0;
            while(j < r){
                while(id[j][i] == 0 && j < r){
                    j++;
                }
                if(j == r){
                    continue;
                }
                else{
                    p[k].first = id[j][i];
                    string tem = "";
                    while(a[j][i] != '*' && j < r){
                        tem = tem + a[j][i];
                        j++;
                    }
                    p[k++].second = tem;
                }
            }
        }
        sort(p, p+k, cmp);
        for(int i = 0; i < k; i++){
            printf("%3d.", p[i].first);
            cout<<p[i].second<<endl;
        }
    }
}
/*
2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0
*/