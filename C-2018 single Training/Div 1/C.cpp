#include<map>
#include<cmath>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
map<char, char> mp;

void init(){
    mp['A'] = 'A';mp['E'] = '3';mp['3'] = 'E';mp['H'] = 'H';mp['I'] = 'I';mp['J'] = 'L';mp['L'] = 'J';
    mp['M'] = 'M';mp['O'] = 'O';mp['S'] = '2';mp['2'] = 'S';mp['T'] = 'T';mp['U'] = 'U';mp['V'] = 'V';
    mp['W'] = 'W';mp['X'] = 'X';mp['Y'] = 'Y';mp['Z'] = '5';mp['5'] = 'Z';mp['1'] = '1';mp['8'] = '8';
}

int main(){
    /*
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    */
    init();
    string s;
    while(getline(cin, s)){
        int mirr = 1, pal = 0;
        string tem = s;
        reverse(s.begin(), s.end());
        if(s == tem){
            pal = 1;
        }
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(mp[s[i]] != tem[i]){
                mirr = 0;
                break;
            }
        }
        cout<<tem<<" -- ";
        if(!mirr){
            if(!pal){
                cout<<"is not a palindrome."<<endl;
            }
            else{
                cout<<"is a regular palindrome."<<endl;
            }
        }
        else{
            if(!pal){
                cout<<"is a mirrored string."<<endl;
            }
            else{
                cout<<"is a mirrored palindrome."<<endl;
            }
        }
        cout<<endl;
    }
}