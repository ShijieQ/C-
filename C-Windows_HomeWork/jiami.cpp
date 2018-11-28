#include<iostream>
#include<cstring>

using namespace std;
const int maxn = 100+10;

void reverse(char s[]){
    int len = strlen(s);
    for(int i = 0; i < len/2; i++){
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}

void change(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = (s[i]-3 >= 'A' ? s[i]-3 : s[i]+23);
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = (s[i]-3 >= 'a' ? s[i]-3 : s[i]+23);
        }
    }
}

void exchange(char s[]){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 'a' - 'A';
        }
        else{
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

int main(){
    char s[maxn];
    cin>>s;
    change(s);
    reverse(s);
    exchange(s);
    cout<<s<<endl;
    return 0;
}
/*
Trvdizrrvj
ABCDEF
*/