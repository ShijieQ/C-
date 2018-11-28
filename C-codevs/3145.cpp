#include<iostream>
#include<algorithm>
using namespace std; 
//long long int num = 0;
void Move(int n,char orin, char target)
{
//	num++;
//    cout << n << " from " << orin << " to " << target << endl;
	if(orin == 'A' && target == 'B')
		cout << orin << " -> " << target << "    " << endl;
	if(orin == 'A' && target == 'C')
		cout << orin << "    ->   " << target << endl;
	if(orin == 'B' && target == 'C')
	    cout << "     B -> C"<<endl;
	if(orin == 'B' && target == 'A')
		cout << orin << " <- " << target << "    " << endl;
	if(orin == 'C' && target == 'A')
		cout << orin << "    <-   " << target << endl;
	if(orin == 'C' && target == 'B')
	    cout << "     B <- C"<<endl;
}

void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        Move(n, a, c);
    }
    else
    {
        Hanoi(n - 1, a, c, b);
        Move(n, a, c);
        Hanoi(n - 1, b, a, c);
    }
}

int main()
{
	int n;
	int sum[15];
	sum[1] = 1;
	cin>>n;
	for(int i = 2; i <= n; i++)
		sum[i] = 2*sum[i-1] + 1;
	cout<<sum[n]<<endl;
	Hanoi(n,'A','B','C');
	return 0;
}
