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

double getDist(POINT p1, POINT p2)//����p1 p2����֮��ľ���
{
	return(p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
double getCross(POINT p0, POINT p1, POINT p2)//�ж�ֱ��p0��p1��б����ֱ��p0��p2��б���Ƿ����
											 //���������һ��ֱ���ϣ����Ϊ��
{
	return(p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

bool cmp(POINT p1, POINT p2)//�ú����������Ǹ���sort������ô����
{
	if (getCross(base, p1, p2) == 0)//���������һ��ֱ����
	{
		return getDist(base, p1) < getDist(base, p2);//����sort��������������ߵĵ�ľ��� ���н�������
													 //��������һ��ֱ���ϣ����������е�Ϊ���ģ��ɽ���Զ����
	}
	return getCross(base, p1, p2) > 0;//����ֱ��p0pi��б�ʽ���б����������
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
			pos = i;//��¼���е�������ߵĵ���±�
		}
	}
	swap(p[0], p[pos]);//swap�Ǹ�������������std���ļ��������ߵĵ���Ϊ������p[0]
}
bool getConvexHull()
{
	if (n < 3)
	{
		return false;
	}
	sort(p + 1, p + n, cmp);//sort������Ҫ��<algorithm>ͷ�ļ�����
	//sort(begin,end)���������ֱ��ʾ������������׵�ַ��β��ַ��Ĭ������Ϊ��������
	//�����Լ�дһ��cmp�������������ɽ��򣨼�������ʽ��
	//���ﲻ��Ҫ��cmp����������������ǹ��򣬵�cmp����return a>b;ʱ�����Ǹ���sort�������Ӵ�С����
	stk[0] = p[0];//ȫ�ֱ���
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
		memset(vis, false, sizeof(vis));//memset��������ǽ������Ե����ֽ���������ķ�ʽ�ŵ�ָ�����ڴ���ȥ/ʤ��is �Ǹ�ȫ�ֱ���
		//menset����������<string.h>��<memory.h>��ͷ�ļ���
		for (int i = 0; i < n; ++i)//n�Ǹ�ȫ�ֱ���
		{
			cin>>p[i].x>> p[i].y;//p�Ǹ�ȫ�ֱ���
			p[i].id = i;
		}
		getBase();//�ҳ�����ߵĵ㣬��������Ϊ�����ĵ�p[0]
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
