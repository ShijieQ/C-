#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
#include<iomanip>
using namespace std;
int dp[2005][2005];
int main()
{
    string a,b,c;
    while(cin >> a)
    {
        cin >> b >> c;
        if(a.size() + b.size() != c.size())  //注意判断长度
        {
            cout << "No\n";
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= a.size(); i++)  //a的数量
        {
            for (int j = 0; j <= b.size(); j++)  //b的数量
            {
                if (c[i + j] == a[i])
                {
                    dp[i + 1][j] |= dp[i][j];
                }
                if (c[i + j] == b[j])
                {
                    dp[i][j + 1] |= dp[i][j];
                }
            }
        }
        if (dp[a.size()][b.size()])cout << "Yes" << endl;
        else cout << "No\n";
    }
    return 0;
}
