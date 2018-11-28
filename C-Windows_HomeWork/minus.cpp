
#include <iostream>
using namespace std;

int StoA(string s, int a[])
{
    int n = s.size();
    for (int i = 0; i < n; i++)
        a[n - 1 - i] = s[i] - 48;
    return n;
}

string AtoS(int a[], int n)
{
    string s = "";
    for (int i = 0; i < n; i++)
    {
        char t = a[i] + 48;
        s = t + s;
    }
    return s;
}

int Subtract(int a[], int n1, int b[], int n2, int c[])
{
    int len = n2 > n1 ? n2:n1;
    bool flag = 1;
    for(int i = 0; i < len; i++){
        if(!flag){
            a[i]--;
            flag = 1;
        }
        c[i] = a[i] - b[i];
        if(c[i] < 0){
            c[i] += 10;
            flag = 0;
        }
    }
    return len;
}
int main()
{
    string s1 = "389";
    int a[1000], n1;
    string s2 = "34";
    int b[1000], n2;
    string s3 = "";
    int c[1000], n3;
    n1 = StoA(s1, a);           
    n2 = StoA(s2, b);           
    n3 = Subtract(a, n1, b, n2, c); 
    s3 = AtoS(c, n3);           
    cout << s3 << endl;
    return 0;
}

