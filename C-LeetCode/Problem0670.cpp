class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string now(s);
        sort(s.begin(), s.end(), [](char a, char b) {return a > b;});
        int index = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != now[i]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return num;
        }
        for (int i = s.size()-1; i > index; i--) {
            if (now[i] == s[index]) {
                swap(now[i], now[index]);
                break;
            }
        }
        return stoi(now);
    }
};