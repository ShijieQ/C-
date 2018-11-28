#include <iostream>
using namespace std;
// ����leapYear

int mday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapYear(int y){
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

// ����whatDay������ĳ��ĳ�µĺ������ڼ�
// ������year-�꣬month-��
// ����ֵ��--7�ֱ��ʾ����һ��������
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
    // �ꡢ�¡����ڼ�
    int y, m, xq;
    // ��������
    cin >> y >> m;
    // �������ڼ�
    xq = whatDay(y, m);
    // �������
    cout << y << "��" << m << "��1��������";
    if (xq == 7)
        cout << "��" << endl;
    else
        cout << xq << endl;
    return 0;
}

