class Solution {
public:
    int rand10() {
        int a = rand7(), b = rand7();
        while (a == 7) {
            a = rand7();
        }
        while (b > 5) {
            b = rand7();
        }
        return (a&1 ? 0:5)+b;
    }
};