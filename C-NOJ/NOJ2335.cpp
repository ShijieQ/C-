#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e6+10;
unsigned long long int positive_max = 0;
unsigned long long int negative_max = 9223372036854775808;
bool positive_flag = 0;

inline void read() {
    unsigned long long int x = 0;
    char c;
    int t = 1;
    while (!isdigit(c = getchar())) { 
        if (c == '-') { 
            t = -1;
        }
    }
    while (isdigit(c)) { 
        x = x*10 + c - '0';
        c = getchar();
    }
    if (t == 1) {
        positive_flag = 1;
        if (positive_max < x) {
            positive_max = x;
        }
    }
    else {
        if (negative_max > x) {
            negative_max = x;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        read();
    }
    if (positive_flag) {
        cout<<positive_max<<endl;
    }
    else {
        cout<<"-"<<negative_max<<endl;
    }
    return 0;
}