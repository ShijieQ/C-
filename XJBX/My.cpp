#include<bits/stdc++.h>

using namespace std;

string Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) 
            ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
        cout<<"mx = "<<mx<<", id = "<<id<<", reslen = "<<resLen<<", resCenter = "<<resCenter<<endl;
    }
    cout<<"(resCenter - resLen)/2 = "<<(resCenter - resLen)/2<<endl;
    cout<<"resLen - 1 = "<<resLen - 1<<endl;
    return s.substr((resCenter - resLen)/2, resLen - 1);
}

int main() {
    cout << Manacher("cbbd");
    return 0;
}