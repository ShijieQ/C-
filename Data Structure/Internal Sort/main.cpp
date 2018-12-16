#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<windows.h>

using namespace std;
typedef int KeyType;
typedef int DataType;
const int MaxSize = 5e7+10;

typedef struct entry {
    KeyType key;
    DataType data;
}Entry;

typedef struct list {
    int n;
    Entry D[MaxSize];
}List;

List l, l_temp;
void Init(int k){
    l.n = k;
    freopen("data.in", "w", stdout);
    srand((int)time(NULL));
    for(int i = 0; i < k; i++){
        l.D[i].key = int(rand());
        l_temp.D[i].key = l.D[i].key;
        printf("%d\n", l.D[i].key);
    }
    fclose(stdout);
}

void Reversion(){
    for(int i = 0; i < l.n; i++){
        l.D[i] = l_temp.D[i];
    }
    return ;
}

void Result(){
    int length = l.n;
    for(int i = 0; i < length; i++){
        cout<<l.D[i].key<<endl;
    }
    return ;
}

long SelectSort(){
    clock_t begin = clock();
    int length = l.n;
    for(int i = 0; i < length; i++){
        int temp = i;
        for(int j = i+1; j < length; j++){
            if(l.D[temp].key > l.D[j].key){
                temp = j;
            }
        }
        swap(l.D[i], l.D[temp]);
    }
    clock_t end = clock();
    return end - begin;
}

long InsertSort(){
    clock_t begin = clock();
    int length = l.n;
    for(int i = 1; i < length; i++){
        Entry temp = l.D[i];
        int j;
        for(j = i-1; j >= 0; j--){
            if(temp.key < l.D[j].key){
                l.D[j+1] = l.D[j];
            }
            else{
                break;
            }
        }
        l.D[j+1] = temp;
    }
    clock_t end = clock();
    return end - begin;
}

long BubbleSort(){
    clock_t begin = clock();
    int length = l.n;
    for(int i = 0; i < length; i++){
        bool flag = 0;
        for(int j = 0; j < length-i-1; j++){
            if(l.D[j].key > l.D[j+1].key){
                swap(l.D[j].key, l.D[j+1].key);
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
    clock_t end = clock();
    return end - begin;
}

long QuickSort(int start, int ending){
    if(start >= ending){
        return 0;
    }
    clock_t begin = clock();
    int mid = start-1;
    Entry flag = l.D[ending];
    for(int i = start; i <= ending-1; i++){
        if(l.D[i].key < flag.key){
            mid++;
            swap(l.D[i], l.D[mid]);
        }
    }
    swap(l.D[++mid], l.D[ending]);
    QuickSort(start, mid-1);
    QuickSort(mid+1, ending);
    clock_t end = clock();
    return end - begin;
}

int main(){
    Init(10000);
    freopen("main.out", "w", stdout);
    QuickSort(0, 9999);
    Result();
    return 0;
}

