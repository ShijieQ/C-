#include <stdio.h>
#include <iostream>
#include "whatDay.h"

// ����printMonth����Ҫ��ĸ�ʽ��ӡĳ��ĳ�µ�����
// ������year-�꣬month-��
// ����ֵ����
// leapYear���ж�����
// ������y-��
// ����ֵ��1-�����꣬0-��������
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
    std::cout<<"  һ  ��  ��  ��  ��  ��  ��"<<std::endl;
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
    // �ꡢ��
    int y, m;
    // ��������
    std::cin >> y >> m;
    // ��������µ�����
    printMonth(y, m);
    return 0;
}
