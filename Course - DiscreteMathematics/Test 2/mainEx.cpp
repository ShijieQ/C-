#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e4+10;
typedef int eletype;
int n, N;
eletype element[maxn];
map<eletype, int> mp;
bool a[maxn][maxn];
bool tem[maxn][maxn];

bool zifan(){
    for(int i = 1; i <= n; i++){
        if(!a[i][i]){
            return false;
        }
    }
    return true;
}

bool fanzifan(){
    for(int i = 1; i <= n; i++){
        if(a[i][i]){
            return false;
        }
    }
    return true;
} 

bool duicheng(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(a[i][j] != a[j][i]){
                return false;
            }
        }
    }
    return true;
}

bool fanduicheng(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i][j] && a[j][i]){
                return false;
            }
        }
    }
    return true;
}

bool chuandi(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            tem[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tem[j][i]){
                for(int k = 1; k <= n; k++){
                    tem[j][k] = tem[j][k] | tem[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != tem[i][j]){
                return false;
            }
        }
    }
    return true;
}

void read(){
    memset(a, 0, sizeof(a));
    cout<<"Please input the number of elements: ";
    cin>>n;
    cout<<"Please input the elements: "<<endl;
    for(int i = 1; i <= n; i++){
        cin>>element[i];
        mp[element[i]] = i;
    }
    cout<<"Please input the number of relations: ";
    cin>>N;
    for(int i = 1; i <= N; i++){
        eletype tema, temb;
        cin>>tema>>temb;
        a[mp[tema]][mp[temb]] = 1;
    }
}

void output(){
    cout<<"��ϵ����Ϊ�� "<<endl;
    cout<<"* ";
    for(int i = 1; i <= n; i++){
        cout<<element[i]<<" ";
    }
    cout<<endl;
    for(int i = 1; i <= n; i++){
        cout<<element[i]<<" ";
        for(int j = 1; j <= n; j++){
            cout<<(a[i][j] ? "1 " : "0 ");
        }
        cout<<endl;
    }
}

int main(){
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    read();
    cout<<endl<<endl;
    output();
    cout<<(zifan() ? "�ü��Ͼ����Է���" : "�ü��ϲ������Է���")<<endl;
    cout<<(fanzifan() ? "�ü��Ͼ��з��Է���" : "�ü��ϲ����з��Է���")<<endl;
    cout<<(duicheng() ? "�ü��Ͼ��жԳ���" : "�ü��ϲ����жԳ���")<<endl;
    cout<<(fanduicheng() ? "�ü��Ͼ��з��Գ���" : "�ü��ϲ����з��Գ���")<<endl;
    cout<<(chuandi() ? "�ü��Ͼ��д�����" : "�ü��ϲ����д�����")<<endl;
    return 0;  
}