#pragma once
class Matrix
{
public:
	double Det;
	int dimM, dimN;//矩阵的维度，即m*n
	double **element;//二维数组作为矩阵
	Matrix();//无参构造函数，默认构建2000*2000维矩阵
	Matrix(const Matrix &b);//拷贝构造函数
	Matrix(int m, int n);//含参构造函数，构造m*n维矩阵
	void Change();//修改矩阵的元素值，批量修改，用于创建结束后的赋值
	void Output();//输出矩阵信息，内部可修改格式
	Matrix operator+(const Matrix b);//重载加法运算符，实现同维矩阵直接相加运算
	Matrix operator*(const int b);//重载乘法运算符，实现矩阵直接数乘运算
	Matrix operator*(const Matrix b);//重载乘法运算符，实现矩阵直接相乘运算
	void det();//若矩阵为方阵，则求出其对应行列式的值
	~Matrix();//析构函数，释放二维数组内存
};
#include "Matrix.cpp"

