#include <iostream>
using namespace std;
// 函数leapYear

int mday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapYear(int y){
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

// 函数whatDay：计算某年某月的号是星期几
// 参数：year-年，month-月
// 返回值：--7分别表示星期一到星期日
int whatDay(int year, int month){
    long long int day = 1;
    for(int i = 1; i < year; i++){
        if(leapYear(i)){
            day += 366;
        }
        else{
            day += 365;
        }
    }
    for(int i = 1; i < month; i++){
        day += mday[i];
    }
    if(month > 2 && leapYear(year)){
        day++;
    }
    return day%7;
}

int main(){
    // 年、月、星期几
    int y, m, xq;
    // 输入年月
    cin >> y >> m;
    // 计算星期几
    xq = whatDay(y, m);
    // 输出星期
    cout << y << "年" << m << "月1日是星期";
    if (xq == 7)
        cout << "日" << endl;
    else
        cout << xq << endl;
    return 0;
}

