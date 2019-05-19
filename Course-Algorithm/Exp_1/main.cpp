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
        cout<<l.D[i].key<<"  ";
        if((i+1) % 10 == 0){
            cout<<endl;
        }
    }
    cout<<endl;
    return ;
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

void AdjustDown(int b, int r){
    Entry temp = l.D[b];
    for(int j = 2*b+1; j <= r; j = j*2+1){
        if(j < r && l.D[j].key < l.D[j+1].key){
            j++;
        }
        if(temp.key > l.D[j].key){
            break;
        }
        l.D[b] = l.D[j];
        b = j;
    }
    l.D[b] = temp;
}

int main(){
    clock_t be = clock();
    Init(10000000);
    clock_t ed = clock();
    freopen("data.out", "w", stdout);
    cout<<"After Init :"<<endl;
    cout<<"time used : "<<ed - be<<"ms"<<endl;
    // Result();
    cout<<"After QuickSort :"<<endl;
    cout<<"time used : "<<QuickSort(0, l.n-1)<<"ms"<<endl;
    // Result();
    Reversion();
    cout<<"After MergeSort :"<<endl;
    cout<<"time used : "<<MergeSort()<<"ms"<<endl;
    // Result();
    return 0;
}