#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e5;
char a[maxn];
//second function
char k[] ={"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"};

void init(){
    a['1'] = '`';a['2'] = '1';a['3'] = '2';a['4'] = '3';a['5'] = '4';a['6'] = '5';a['7'] = '6';a['8'] = '7';a['9'] = '8';a['0'] = '9'; a['-'] = '0';a['='] = '-';
    a['W'] = 'Q';a['E'] = 'W';a['R'] = 'E';a['T'] = 'R';a['Y'] = 'T';a['U'] = 'Y';a['I'] = 'U';a['O'] = 'I';a['P'] = 'O';a['['] = 'P'; a[']'] = '[';a['\\'] = ']';
    a['S'] = 'A';a['D'] = 'S';a['F'] = 'D';a['G'] = 'F';a['H'] = 'G';a['J'] = 'H';a['K'] = 'J';a['L'] = 'K';a[';'] = 'L';
    a['X'] = 'Z';a['C'] = 'X';a['V'] = 'C';a['B'] = 'V';a['N'] = 'B';a['M'] = 'N';a[','] = 'M';a['.'] = ',';a['/'] = '.';a['['] = 'P'; a[']'] = '[';a['\\'] = ']';   
    a[' '] = ' ';a['\n'] = '\n';
    a['\''] = ';';
}

int main(){
    /*
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    */
    init();
    char c;
    while((c = getchar()) != EOF){
        cout<<a[c];
    }
}
/*
O S, GOMR YPFSU/
FHSDGKDHGURNGIUNG GNUDNGIURGJDKNSFIJES
*/