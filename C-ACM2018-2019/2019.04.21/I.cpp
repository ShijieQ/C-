#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e3+10;
string a, b, add;
int lena, lenb, lenadd;
bool dp[maxn][maxn];

int main(){
    int T;
    cin>>T;
    while(T--){    
        cin>>a>>b>>add;
        lena = a.length(), lenb = b.length(), lenadd = add.length();
        //a += " ", b += " ", add += " ";
        a = " " + a, b = " " + b, add = " " + add;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = dp[0][1] = 1;
        for(int i = 1; i <= lena; i++){
            for(int j = 1; j <= lenb; j++){
                if(a[i] == add[i + j]){
                    dp[i][j] += dp[i - 1][j];
                }
                if(b[j] == add[i + j]){
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        cout<<(dp[lena][lenb] ? "Yes":"No")<<endl;
    }
    return 0;
}