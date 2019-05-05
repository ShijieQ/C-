#include<iostream>
using namespace std;

int main()
{
    int n;
    char* c = new char[51];
    cin >> n >> c;
    
    for (int i = 0; c[i] != '\0'; i++)
    {
        c[i] += n % 26;
        if (c[i] > 'z')
        {
            c[i] -= 26;
        }
    }
    cout << c;
    return 0;
}
