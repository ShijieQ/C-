#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
void init(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
}

int main(){
    init();
    int T;
    cin >> T;
    while (T--){
        int p;
        cin >> p;
        for (int i = 0; i < p; i++){
            for (int j = 0; j < p; j++){
                cout << (i + j) % p << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < p; i++){
            for (int j = 0; j < p; j++){
                cout << (i * j) % p << " ";
            }
            cout << endl;
        }
    }
}