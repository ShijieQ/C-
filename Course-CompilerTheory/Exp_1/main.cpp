#include <bits/stdc++.h>

#define Reserved 1
#define Tag 2
#define Number 3
#define Operation 4
#define Separator 5

using namespace std;

string buffer;
char ch;
// vector<pair<int, string> > ans;
unordered_map<string, int> Check;

void init() {
    freopen("temp.out", "r", stdin);
    freopen("ans.out", "w", stdout);
    Check["if"] = 1; Check["int"] = 1; Check["for"] = 1; Check["while"] = 1; Check["do"] = 1; 
    Check["return"] = 1; Check["break"] = 1; Check["continue"] = 1; Check["else"] = 1;Check["double"] = 1;
    Check["float"] = 1;

    Check["+"] = 4; Check["-"] = 4; Check["*"] = 4; Check["/"] = 4; Check["="] = 4; Check[">"] = 4;
    Check["<"] = 4; Check[">="] = 4; Check["<="] = 4; Check["!="] = 4;
    
    Check[","] = 5; Check[";"] = 5; Check["{"] = 5; Check["}"] = 5; Check["("] = 5; Check[")"] = 5;
    Check[":"] = 5;
}

string toString(char ch1) {
    string s = "";
    s = s + ch1;
    return s;
}

void removeNote() {
    //freopen("data.in", "r", stdin);
    //freopen("temp.out", "w", stdout);
    char ch = getchar();
    while (ch != EOF) {
        if (ch == '/') {
            if ((ch = getchar()) == '/') {
                while ((ch = getchar()) != '\n');
                ch = getchar();
            }
        }
        putchar(ch);
        ch = getchar();
    }
}

// 1
bool isReserved() {
    return (Check[buffer] == Reserved);
}

// 4
bool isOperation() {
    return (Check[buffer] == Operation);
}

// 5
bool isSeparator() {
    return (Check[buffer] == Separator);
}

// void outPut() {
//     for (int i = 0; i < ans.size(); i++) {
//         cout<<"("<<ans[i].first<<", '"<<ans[i].second<<"')"<<endl;
//     }
// }

int main() {
    removeNote();
    init();
    
    ch = getchar();
    while (ch != EOF) {
        buffer = ch;
        if (isalpha(ch) || ch == '_') {
            ch = getchar();
            while ((ch != EOF) && (isalpha(ch) || ch == '_')) {
                buffer = buffer + toString(ch);
                ch = getchar();
            }
            if (isReserved()) {
                cout<<"("<<Reserved<<", '"<<buffer<<"')"<<endl;
            }
            else {
                cout<<"("<<Tag<<", '"<<buffer<<"')"<<endl;
            }
            continue;
        }
        else if (isalnum(ch)) {
            ch = getchar();
            while ((ch != EOF) && isalnum(ch)) {
                buffer = buffer + toString(ch);
                ch = getchar();
            }
            cout<<"("<<Number<<", '"<<buffer<<"')"<<endl;
            continue;
        }
        else if (isOperation() || buffer == "!") {
            if (buffer == "!" && (ch = getchar()) == '=') {
                cout<<"("<<Operation<<", '"<<buffer<<"=')"<<endl;
            }
            if (buffer == ">" || buffer == "<") {
                if ((ch = getchar()) == '=') {
                    buffer = buffer + "=";
                }
                cout<<"("<<Operation<<", '"<<buffer<<"')"<<endl;
            }
            if (isOperation()) {
                cout<<"("<<Operation<<", '"<<buffer<<"')"<<endl;
            }
            ch = getchar();
            continue;
        }
        else if (isSeparator()) {
            cout<<"("<<Separator<<", '"<<buffer<<"')"<<endl;
            ch = getchar();
            continue;
        }
        else if (buffer == " " || buffer == "\n") {
            ch = getchar();
        }
    }
    return 0;
}