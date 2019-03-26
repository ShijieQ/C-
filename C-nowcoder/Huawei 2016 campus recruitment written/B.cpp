#include <map>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<pair<string, int>> vec;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

int main(){
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    string s;
    int pos;
    while(getline(cin, s)){
        int p = s.rfind('\\');
        string temp = s.substr(p + 1);
        //cout<<temp<<endl;
        int siz = vec.size();
        int flag = -1;
        for(int i = 0; i < siz; i++){
            if(vec[i].first == temp){
                //cout<<"temp = "<<temp<<" vec["<<i<<"].first = "<<vec[i].first<<endl;
                flag = i;
                break;
            }
        }
        if(flag != -1){
            vec[flag].second++;
        }
        else{
            vec.push_back(make_pair(temp, 1));
        }
        //cout<<"size = "<<vec.size()<<endl;
    }
    sort(vec.begin(), vec.end(), cmp);
    int siz = vec.size();
    if(siz > 8) siz = 8;
    for(int i = 0; i < siz; i++){
        int po = vec[i].first.find(" ");
        if(po > 16){
            cout<<vec[i].first.substr(po - 16)<<" "<<vec[i].second<<endl;
        }
        else{
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }
    return 0;
}