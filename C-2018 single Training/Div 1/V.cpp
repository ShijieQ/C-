#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 8;
char k[maxn][1 << maxn];
map<string, int> mmp;
string s;
string head;

void init(){
    mmp["000"] = 0;
    mmp["001"] = 1;
    mmp["010"] = 2;
    mmp["011"] = 3;
    mmp["100"] = 4;
    mmp["101"] = 5;
    mmp["110"] = 6;
    mmp["111"] = 7;
}

int getnum(string a){
    int len = a.length();
    int ans = 0;
    for (int i = len - 1; i >= 0; i--){
        ans += (a[i] - '0') * pow(2, len - i - 1);
    }
    return ans;
}

void get(){
    memset(k, 0, sizeof(k));
    int len = s.length();
    int l = 1;
    for (int i = 0, j = 0; i < len; i++){
        if (j < (1 << l) - 1){
            k[l][j++] = s[i];
        }
        else{
            k[++l][0] = s[i];
            j = 1;
        }
    }
}

void gethead(){
    head = "";
    for (int i = 0; i < 3; i++){
        char ch = getchar();
        while (ch == '\n'){
            ch = getchar();
        }
        head = head + ch;
    }
}

int main(){
    /*
    freopen("V.in", "r", stdin);
    freopen("V.out", "w", stdout);
    */
    init();
    while (getline(cin, s)){
        //    cout<<"*s = "<<s<<endl;
        get();
        /*
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < (1 << i); j++){
                cout<<k[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        //cout<<k[0][0]<<endl;
        gethead();
        while (head != "000"){
            // cout<<"head = "<<head<<endl;
            int temm = mmp[head];
            string t;
            string tmp;
            for (int i = 0; i < temm; i++){
                tmp = tmp + '1';
            }
            // cout<<"tmp = "<<tmp<<endl;
            // cout<<"temm = "<<temm<<endl;
            while (1){
                for (int i = 1; i <= temm; i++){
                    char ch = getchar();
                    while (ch == '\n'){
                        ch = getchar();
                    }
                    t = t + ch;
                }
                //        cout<<"t = "<<t<<endl;
                if (t != tmp){
                    int temk = getnum(t);
                    // cout<<"temk = "<<temk;
                    cout << k[temm][temk];
                }
                else{
                    break;
                }
                t = "";
            }
            gethead();
            // cout<<"head = "<<head<<endl;
            // cout<<"s = "<<s<<endl;
        }
        cout << endl;
        if (getchar() == EOF)
            break;
    }
}