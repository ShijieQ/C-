#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int const Max = 1e5;
struct POINT
{
	double x, y;
	int id;
}base, p[Max], stk[Max];

bool vis[Max];
int n, top;

double getDist(POINT p1, POINT p2)//返回p1 p2两点之间的距离
{
	return(p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
double getCross(POINT p0, POINT p1, POINT p2)//判断直线p0与p1的斜率与直线p0与p2的斜率是否相等
											 //如果三点在一条直线上，结果为零
{
	return(p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

bool cmp(POINT p1, POINT p2)//该函数的作用是告诉sort函数怎么排序
{
	if (getCross(base, p1, p2) == 0)//如果三点在一条直线上
	{
		return getDist(base, p1) < getDist(base, p2);//告诉sort函数按照与最外边的点的距离 进行降序排序
													 //若三点在一条直线上，则以年轮中点为中心，由近及远排序
	}
	return getCross(base, p1, p2) > 0;//按照直线p0pi的斜率进行斜率升序排序
}
void getBase()
{
	base.x = p[0].x;
	base.y = p[0].y;
	int pos = 0;
	for (int i = 0; i < n; ++i)
	{
		if (p[i].y < base.y || (p[i].x < base.x && p[i].y == base.y))
		{
			base.x = p[i].x;
			base.y = p[i].y;
			pos = i;//记录所有点中最外边的点的下标
		}
	}
	swap(p[0], p[pos]);//swap是个交换函数，在std库文件里，把最外边的点作为基础点p[0]
}
bool getConvexHull()
{
	if (n < 3)
	{
		return false;
	}
	sort(p + 1, p + n, cmp);//sort函数需要用<algorithm>头文件包含
	//sort(begin,end)两个参数分别表示待排序数组的首地址和尾地址，默认排序为升序排序
	//可以自己写一个cmp函数，则可升序可降序（即该题形式）
	//这里不需要对cmp函数传入参数，这是规则，当cmp函数return a>b;时，这是告诉sort函数，从大到小排序
	stk[0] = p[0];//全局变量
	stk[1] = p[1];
	top = 1;
	bool flag = false;
	for (int i = 2; i < n; ++i)
	{
		while (top > 0 && getCross(stk[top - 1], stk[top], p[i]) < 0)
		{
			top--;
		}
		if (top > 0 && getCross(stk[top - 1], stk[top], p[i]) > 0)
		{
			flag = true;
		}
		stk[++top] = p[i];
	}
	if (top > 1 && flag)
	{
		for (int i = 0; i <= top; i++)
		{
			vis[stk[i].id] = true;
		}
		return true;
	}
	return flag;
}
void Delete()
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!vis[p[i].id])
		{
			p[cnt++] = p[i];
		}
	}
	n = cnt;
	memset(stk, 0, sizeof(stk));
	memset(vis, false, sizeof(vis));
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin>>n;
		memset(vis, false, sizeof(vis));//memset这个函数是将数字以单个字节逐个拷贝的方式放到指定的内存中去/胜利is 是个全局变量
		//menset函数包含在<string.h>或<memory.h>的头文件中
		for (int i = 0; i < n; ++i)//n是个全局变量
		{
			cin>>p[i].x>> p[i].y;//p是个全局变量
			p[i].id = i;
		}
		getBase();//找出最外边的点，并将其作为基础的点p[0]
		int ans = 0;
		while (getConvexHull())
		{
			ans++;
			Delete();
			getBase();
		}
		if (ans == 0)
		{
			cout << "unlucky!\n";
		}
		else
			cout << ans << endl;
	}
	system("pause");
	return 0;
}
