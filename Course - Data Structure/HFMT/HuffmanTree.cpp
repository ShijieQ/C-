#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef char ElementType;
const int maxn = 500+5;
const int INF = 0x3f3f3f3f;

typedef struct HuffmanTree{
    ElementType Data;
    int w;
    int parent, lchild, rchild;
} HuffmanTree;

void CreateHuffmanTree(HuffmanTree Ht[], int N){
    for(int i = 1; i < 2*N; i++){
        Ht[i].parent = Ht[i].lchild = Ht[i].rchild = -1;
    }
    for(int i = N+1; i < 2*N; i++){
        int min1, min2, lmin, rmin;
        min1 = min2 = INF;
        lmin = rmin = -1;
        for(int k = 1; k <= i-1; k++){
            if(Ht[k].parent == -1){
                if(Ht[k].w < min1){
                    min2 = min1;
                    rmin = lmin;
                    min1 = Ht[k].w;
                    lmin = k;
                }
                else if(Ht[k].w < min2){
                    min2 = Ht[k].w;
                    rmin = k;
                }
            }
        }
        Ht[lmin].parent = i;
        Ht[rmin].parent = i;
        Ht[i].w = Ht[lmin].w + Ht[rmin].w;
        Ht[i].lchild = lmin;
        Ht[i].rchild = rmin;
    }
}

void getcode(const HuffmanTree Ht[], int k, char s[], int num){
    if(Ht[k].rchild == -1 && Ht[k].lchild == -1){
        cout<<Ht[k].Data<<" :";
        for(int i = 0; i < num; i++){
            cout<<s[i];
        }
        cout<<endl;
        return ;
    }
    s[num] = '0';
    getcode(Ht, Ht[k].lchild, s, ++num);
    num--;
    s[num] = '1';
    getcode(Ht, Ht[k].rchild, s, ++num);
}

void TranslateCode(const HuffmanTree Ht[], const char target[], int n){
    int len = strlen(target);
    int k = 2*n - 1;
    for(int i = 0; i < len; ){
        while(Ht[k].lchild != -1 && Ht[k].rchild != -1){
            if(target[i] == '0')
                k = Ht[k].lchild;
            if(target[i] == '1')
                k = Ht[k].rchild;
            i++;
        }
        cout<<Ht[k].Data;
        k = 2*n - 1;
    }
    cout<<endl;
}

int main(){
    HuffmanTree Ht[2*maxn];
    int n;
    cout<<"Please input the number of nodes : ";
    cin>>n;
    cout<<"Please input the weight and the data : "<<endl;
    for(int i = 1; i <= n; i++){
        cin>>Ht[i].w>>Ht[i].Data;
    }
    CreateHuffmanTree(Ht, n);
    char s[maxn];
    cout<<"The code is : "<<endl;
    getcode(Ht, 2*n-1, s, 0);
    char target[maxn];
    cout<<"Please input the code what will be decoded: ";
    cin>>target;
    TranslateCode(Ht, target, n);
    return 0;
}
/*
6
28 A
23 B
15 C
9 D
11 E
14 F
1001111000001110101110110
*/