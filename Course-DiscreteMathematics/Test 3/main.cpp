#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 2e4+10;
pair<int, int> relation[maxn];
bool check_[maxn];
int factor[maxn];
bool mp[maxn][maxn];
int num = 0;
int relaNum = 0;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}

void calFactor(int k){
    memset(factor, 0, sizeof(factor));
    for(int i = 1; i <= sqrt(k); i++){
        if(!(k%i)){
            factor[num++] = i;
            if(i != k/i){
                factor[num++] = k/i;
            }
        }
    }
}

void getRelation(){
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(!(factor[i]%factor[j])){
                mp[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            for(int k = 0; k < num; k++){
                mp[k][k] = 0;
                if(mp[i][k] && mp[k][j]){
                    mp[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(mp[i][j]){
                relation[relaNum].first = factor[j];
                relation[relaNum++].second = factor[i];
            }
        }
    }
    sort(relation, relation+relaNum, cmp);
}

void OutputRelation(){
    cout<<"COV A = {";
    if(!relaNum){
        cout<<" null }"<<endl;
        return ;
    }
    else {
        cout<<"<"<<relation[0].first<<", "<<relation[0].second<<">";
    }
    for(int i = 1; i < relaNum; i++){
        cout<<", <"<<relation[i].first<<", "<<relation[i].second<<">";
    }
    cout<<"}"<<endl;
}

bool check(int k){
    for(int i = 0; i < num; i++){
        if(check_[i]){
            continue;
        }
        for(int j = 0; j < num; j++){
            if(gcd(factor[i], factor[j]) == 1 && lcm(factor[i], factor[j]) == k){
                check_[i] = 1;
                check_[j] = 1;
                break;
            }
        }
    }
    for(int i = 0; i < num; i++){
        if(!check_[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    calFactor(n);
    getRelation();
    OutputRelation();
    if(check(n)){
        cout<<"该集合所构成的格为有补格"<<endl;
    }
    else{
        cout<<"该集合所构成的格不是有补格"<<endl;
    }
    return 0;
}