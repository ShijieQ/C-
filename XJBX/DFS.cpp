#include<bits/stdc++.h>

using namespace std;

class Coverage {
private:
    // vector<vector<bool> > status;
    // vector<string> Existstatus;

public:
    vector<vector<int> > Group; // 组数
    map<string, bool> Allstatus; // 所有的目标状态
    void ALLStatus_DFS(string s, int deep, int n) {
        if (deep == n) {
            Allstatus[s] = 1;
            return ;
        }
        ALLStatus_DFS(s + '0', deep + 1, n);
        ALLStatus_DFS(s + '1', deep + 1, n);
        return ;
    }

    void getAllStatus(int n) {
        ALLStatus_DFS("", 0, n);
        return ;
    }

    void GetCoverage_DFS(int l, int r, bool ischose, int t, vector<int> group) {
        if (l > r) {
            return ;
        }
        if (ischose == 1) {
            group.push_back(l);
        }
        if (t == 0) {
            Group.push_back(group);
            return ;
        }
        GetCoverage_DFS(l + 1, r, 0, t, group);
        GetCoverage_DFS(l + 1, r, 1, t - 1, group);
    }

    int GetCoverage(int l, int r, int t) {
        map<string, bool> temp(Allstatus);
        vector<int> group;
        GetCoverage_DFS(l, r, 0, t, group);
        GetCoverage_DFS(l, r, 1, t - 1, group);
        return Group.size();
    }
};

int main() {
    Coverage test;
    test.getAllStatus(4);
    for (auto &v : test.Allstatus) {
        cout << v.first << endl;
    }
    cout << test.GetCoverage(1, 9, 3) << endl;
    for (int i = 0; i < test.Group.size(); i++) {
        for (int j = 0; j < test.Group[i].size(); j++) {
            cout << test.Group[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}