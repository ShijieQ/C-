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

Entry temp[MaxSize];
long MergeSort(){
    clock_t begin = clock();
    int low, n1, n2, size = 1;
    while(size < l.n){
        int k = 0;
        low = 0;
        while(low + size <= l.n){
            n1 = size;
            if(low + size*2 < l.n){
                n2 = size;
            }
            else{
                n2 = l.n - low - size;
            }
            int i = low, j = low + n1;
            while(i <= low + n1 - 1 && j <= low + n1 + n2 - 1){
                if(l.D[i].key <= l.D[j].key){
                    temp[k++] = l.D[i++];
                }
                else{
                    temp[k++] = l.D[j++];
                }
            }
            while(i <= low + n1 - 1){
                temp[k++] = l.D[i++];
            }
            while(j <= low + n1 + n2 - 1){
                temp[k++] = l.D[j++];
            }
            low += n1 + n2;
        }
        for(int i = 0; i < l.n; i++){
            l.D[i] = temp[i];
        }
        size *= 2;   
    }
    clock_t end = clock();
    return end - begin;
}

void AdjustDown(Entry heap[], int l, int r){
    KeyType temp = heap[l].key;
    for(int j = 2*l; j <= r; j *= 2){
        if(j < m && heap[j].key < heap[j+1].key){
            j++;
        }
        if(temp > heap[j].key){
            break;
        }
        heap[l] = heap[j];
        l = j;
    }
    heap[l] = temp;
}

long HeapSort(){
    clock_t begin = clock();
    for(int i = )
    clock_t end = clock();
    return end - begin;
}

int main(){
    Init(1005);
    freopen("main.out", "w", stdout);
    MergeSort();
    Result();
    return 0;
}

