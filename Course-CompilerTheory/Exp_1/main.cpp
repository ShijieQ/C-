#include <bits/stdc++.h>

#define Reserved 1
#define Tag 2
#define Number 3
#define Operation 4
#define Separator 5

/*
    isalpha();
    isdigit();
    isalnum();
    ungetc(char, stream);
    */

using namespace std;

string buffer;
vector<pair<int, string> > ans;
unordered_map<string, bool > Check;

void init() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    Check["if"] = 1; Check["int"] = 1; Check["for"] = 1; Check["while"] = 1; Check["do"] = 1; 
    Check["return"] = 1; Check["break"] = 1; Check["continue"] = 1;

    Check["+"] = 4; Check["-"] = 4; Check["*"] = 4; Check["/"] = 4; Check["="] = 4; Check[">"] = 4;
    Check["<"] = 4; Check[">="] = 4; Check["<="] = 4; Check["!="] = 4;
    
    Check[","] = 5; Check[":"] = 5; Check["{"] = 5; Check["}"] = 5; Check["("] = 5; Check[")"] = 5;
}

void getallNum() {
    while ()
}

bool isSeparator() {
    return (Check[buffer] == Separator);
}

bool isOperation() {
    return (Check[buffer] == Operation);
}

bool isNumber() {

}

int main() {
    while ((buffer = getchar()) != EOF) {
        
    }
}