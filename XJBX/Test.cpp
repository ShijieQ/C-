#include <iostream>
#include <math.h>
#define MAX 10
using namespace std;
double element[MAX][MAX]; //系数矩阵
int dimM; //最大迭代次数
int temp; //标记最大的数所在的行
double maxx; //比较每列时暂时存放最大的数
double tmp; //用于交换时存放中间变量的
double tmp1; //存储中间变量以减少计算量
int sign = 0; //标记行交换的次数
int main(void)
{
    for (int i = 0; i < dimM-1; i++){
        int temp = i;
        double maxx = element[i][i];
        for (int j = i + 1; j < dimM; j++){
            if (fabs(maxx) < fabs(element[j][i])){
                maxx = element[j][i];
                temp = j;
            }
        }
        if (fabs(maxx) < 0.000001){
            Det = 0;
            break;
        }
        if (temp != i){
            cnt++;
            for (j = i; j <= dimM; j++){
                swap(element[i][j], element[temp][j]);
            }
        }
        for (int j = i + 1; j < dimM; j++){
            double ans = element[j][i] / element[i][i];
            for (int k = i; k < dimM + 1; k++){
                element[j][k] = element[j][k] - element[i][k] * ans;
            }
        }
    }
    ans = 1;
    for (i = 0; i < dimM; i++){
        ans *= element[i][i];
    }
    Det = !(cnt&1) ? ans:-ans;
    return 0;
}
