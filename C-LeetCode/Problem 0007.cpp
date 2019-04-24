#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int k = x;
        long long int ans = 0;
        bool flag = (x < 0);
        if (flag) {
            k = -k;
        }
        while (k != 0) {
            ans = ans*10 + k%10;
            k /= 10;
        }
        if (flag) {
            ans = -ans;
        }
        if (ans > 2147483647 || ans < -2147483648) {
            ans = 0;
        }
        return ans;
    }
};

int main(){
    Solution test;
    int ans = test.reverse(1463847412);
    cout<<ans<<endl;
    return 0;
}