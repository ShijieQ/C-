#include <stdio.h>
#include <iostream>
#include "whatDay.h"

// 函数printMonth：按要求的格式打印某年某月的日历
// 参数：year-年，month-月
// 返回值：无
// leapYear：判断闰年
// 参数：y-年
// 返回值：1-是闰年，0-不是闰年
#ifndef Test
#define Test
int leapYear(int y){
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}
#endif

void printMonth(int year, int month){
    int mday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(leapYear(year)){
        mday[2]++;
    }
    std::cout<<"  一  二  三  四  五  六  日"<<std::endl;
    int first = whatDay(year, month);
    for(int i = 1; i < first; i++){
        std::cout<<"    ";
    }
    for(int i = first; i < first+mday[month]; i++){
        printf("  %2d", i-first+1);
        if(i % 7 == 0){
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}    

int main(){
    // 年、月
    int y, m;
    // 输入年月
    std::cin >> y >> m;
    // 输出该年月的日历
    printMonth(y, m);
    return 0;
}
