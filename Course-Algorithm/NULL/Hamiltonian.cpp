#include<bits/stdc++.h>

using namespace std;
vector<int> x;
vector<vector<int> > a;
int n;
bool flag = 0;

void NextValue(int k) {
    do {
        x[k] = (x[k] + 1)%n;
        if (!x[k]) {
            // cout<<"************************"<<endl;
            return ;
        }
        if (a[x[k - 1]][x[k]]) {
            int j;
            for (j = 0; j < k; j++) {
                if (x[j] == x[k]) {
                    break;
                }
            }
            if (j == k) {
                if ((k < n - 1) || ((k == n - 1) && a[x[n - 1]][x[0]])) {
                    return ;
                }
            }
        }
    } while (1);
}

void Hamiltonian(int k) {
    do {
        NextValue(k);
        if (!x[k]) {
            // for (int i = 0; i < k; i++) {
            //     cout<<x[i]<<" ";
            // }
            // *cout<<endl;
            return ;
        }
        if (k == n - 1) {
            // *cout<<endl;
            for (int i = 0; i < n; i++) {
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }
        else {
            // *cout<<x[k]<<"->";
            Hamiltonian(k + 1);
            // *cout<<"<-"<<x[k];
        }
    } while(1);
}

void dfs(int k, int step, string s) {
    if (step == n && a[k][0]) {
        s += '0';
        cout<<s<<endl;
        return ;
    }
    if (x[k]) {
        return ;
    }
    x[k] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i][k] && !x[i]) {
            char ch = i + '0';
            dfs(i, step + 1, s + ch);
        }
    }
    x[k] = 0;
}

int main() {
    cin>>n;
    a.resize(n, vector<int> (n));
    x.resize(n);
    x[0] = 0;
    int m;
    cin>>m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin>>l>>r;
        a[l][r] = a[r][l] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //Hamiltonian(1);
    dfs(0, 1, "0");
    return 0;
}
/*
8
11
0 1
0 2
0 6
1 2
1 7
2 3
2 5
3 4
4 5
5 6
6 7
*/