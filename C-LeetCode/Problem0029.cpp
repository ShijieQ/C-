class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int ans = 1LL*dividend/divisor;
        return (ans > 2147483647 ? 2147483647:ans);
    }
};