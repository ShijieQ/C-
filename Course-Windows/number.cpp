// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
#include <iomanip> 
using namespace std;
int monthNum[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// 函数printYear：按要求的格式打印某年的日历
// 参数：year-年
// 返回值：无
void printYear(int year);

const char number[][7][6] = {
{{'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
},
{{' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ',' ',' '},
 {'*',' ',' ',' ',' ',' '},
 {'*',' ','*',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
},
{{'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ',' ',' '},
 {'*',' ',' ',' ',' ',' '},
 {'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ',' ',' '},
 {'*',' ',' ',' ',' ',' '},
 {'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
},
{{'*',' ','*',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {' ',' ',' ',' ','*',' '},
 {'*',' ','*',' ','*',' '},
}
};

// leapYear：判断闰年
// 参数：y-年
// 返回值：1-是闰年，0-不是闰年
int leapYear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;
	return 0;
}

// 函数whatDay:计算某年某月的1号是星期几
// 参数：year-年，month-月
// 返回值：1到7--星期1到星期日
int whatDay(int year, int month)
{
	// 1年月日是星期一
	int w = 1;
	int i;

	// 1到year-1都是全年
	for (i = 1; i < year; i++)
	{
		if (leapYear(i))
			w += 366;
		else
			w += 365;
	}
	switch (month)
	{
	case 12: // 加月的
		w += 30;
	case 11: // 加月的
		w += 31;
	case 10: // 加月的
		w += 30;
	case 9:  // 加月的
		w += 31;
	case 8:  // 加月的
		w += 31;
	case 7:  // 加月的
		w += 30;
	case 6:  // 加月的
		w += 31;
	case 5:  // 加月的
		w += 30;
	case 4:  // 加月的
		w += 31;
	case 3:  // 加月的
		if (leapYear(year))
			w += 29;
		else
			w += 28;
	case 2:  // 加月的天
		w += 31;
	case 1:  // 1月不加了
		;
	}

	// 得到-6，其中为星期天
	w = w % 7;

	// 调整星期天
	if (w == 0)
		w = 7;
	return w;
}

// 请在下面补充代码，实现函数printYear
/*************** Begin **************/
void printTwoMonths(int year, int month1, int month2)
{
	//1.获得month1和month2分别多少天以及第一天是星期几
	int day1 = whatDay(year, month1);
	int day2 = whatDay(year, month2);
	int num1 = month1 == 2 ? leapYear(year) + monthNum[2] : monthNum[month1];
	int num2 = month2 == 2 ? leapYear(year) + monthNum[2] : monthNum[month2];
	//2.分别打印month1和month2的第一行
	cout << "                ";
	printf("%2d月        ", month1);
	cout << "                ";
	printf("%2d月\n", month2);
	cout << "一 二 三 四 五 六 日        一 二 三 四 五 六 日" << endl;
	//3.打印剩余的行，考虑：month1和month2中的换行问题和填充空格问题
	int maxx = day1 + num1 > day2 + num2 ? day1 + num1 : day2 + num2;
	//cout<<"maxx :"<<maxx<<endl;
	int line = maxx / 7 + (maxx % 7 ? 1 : 0);
	//cout<<"line :"<<line<<endl;
	int p = 1, q = 1;
	for (int i = 0; i < line; i++) {
		for (int i = 0; i < 7; i++) {
			int tem = p++ - day1 + 1;
			if (tem <= 0 || tem > num1) {
				cout << "  ";
			}
			else {
				printf("%2d", tem);
			}
			cout << " ";
		}
		cout << "       ";
		for (int i = 0; i < 7; i++) {
			int tem = q++ - day2 + 1;
			if (tem <= 0 || tem > num2) {
				cout << "  ";
			}
			else {
				printf("%2d", tem);
			}
			cout << " ";
		}
		cout << endl;
	}
}

void OutputTitle(int year) {
	int num[4];
	for (int i = 0; i < 4; i++) {
		num[i] = year % 10;
		year /= 10;
	}
	for (int k = 0; k < 7; k++)
	{
		for (int i = 0; i < 6; i++)
			cout << number[num[3]][k][i];
		cout << " ";
		for (int i = 0; i < 6; i++)
			cout << number[num[2]][k][i];
		cout << " ";
		for (int i = 0; i < 6; i++)
			cout << number[num[1]][k][i];
		cout << " ";
		for (int i = 0; i < 6; i++)
			cout << number[num[0]][k][i];
		cout << " ";
		cout << endl;
	}
}

void printYear(int year)
{
	for (int i = 1; i < 12; i += 2) {
		printTwoMonths(year, i, i + 1);
		cout << endl;
	}
}


/*************** End **************/


int main()
{
	// 年
	int y;
	// 输入年
	cin >> y;
	// 输出该年的日历
	OutputTitle(y);
	printYear(y);
	return 0;
}

