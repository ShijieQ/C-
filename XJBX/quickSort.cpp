#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn] = {13857,21523,17907,23903};

void qSort(int l, int r)
{
    if(l >= r)  return;
    int mid = l-1, x = a[r];
    for(int j = l; j <= r-1; j++)
    {
        if(a[j] < x)
        {
            mid++;
            swap(a[mid], a[j]);
        }
    }
    swap(a[++mid], a[r]);
    qSort(l, mid-1);
    qSort(mid+1, r);
}

int main()
{
    qSort(0, 3);
    for(int i = 0; i <= 3; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}