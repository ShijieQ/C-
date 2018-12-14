#include "Matrix.h"

#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
const int maxn = 2000;

Matrix::Matrix()
{
	//以默认值申请矩阵空间2000*2000维
	element = new double*[maxn];
	for (int i = 0; i < maxn; i++) {
		element[i] = new double[maxn];
	}
	//初始化矩阵为零矩阵
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			element[i][j] = 0;
		}
	}
	dimM = dimN = maxn;
}

Matrix::Matrix(const Matrix &b)
{
	//根据所拷贝的矩阵的维度设置矩阵维度
	dimM = b.dimM;
	dimN = b.dimN;
	//申请二维数组空间
	element = new double*[dimM];
	for (int i = 0; i < dimM; i++) {
		element[i] = new double[dimN];
	}
	//将所拷贝的矩阵的元素进行赋值到当前矩阵
	for (int i = 0; i < dimM; i++) {
		for (int j = 0; j < dimN; j++) {
			element[i][j] = b.element[i][j];
		}
	}
}

Matrix::Matrix(int m, int n)
{
	//根据参数m、n，申请二维数组空间
	element = new double*[m];
	for (int i = 0; i < m; i++) {
		element[i] = new double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			element[i][j] = 0;//初始化为零矩阵
		}
	}
	dimM = m;
	dimN = n;
}

void Matrix::Change()
{
	std::cout << "Please input the element(" << dimM << " X " << dimN << ")" << std::endl;
	for (int i = 0; i < dimM; i++) {
		for (int j = 0; j < dimN; j++) {
			std::cin >> element[i][j];//循环输入
		}
	}
	//当为方阵时，计算对应行列式的值
	if (dimM == dimN) {
		det();
	}
}

void Matrix::Output()
{
	std::cout << "This matrix is(" << dimM << " X " << dimN << "): " << std::endl;
	for (int i = 0; i < dimM; i++) {
		for (int j = 0; j < dimN; j++) {
			printf("%7.1f", element[i][j]);//循环输出
		}
		std::cout << std::endl;
	}
}

Matrix Matrix::operator+(const Matrix b)
{
	//当两个矩阵的维度不同时，输出错误信息，并返回前一个矩阵
	if (dimM != b.dimM || dimN != b.dimN) {
		std::cout << "Error, please check the dimensions of your matrixs." << std::endl;
		return *this;
	}
	Matrix ans(dimM, dimN);
	//循环相加
	for (int i = 0; i < dimM; i++) {
		for (int j = 0; j < dimN; j++) {
			ans.element[i][j] = element[i][j] + b.element[i][j];
		}
	}
	return ans;
}

Matrix Matrix::operator*(const int b)
{
	Matrix ans(*this);
	//循环进行数乘运算
	for (int i = 0; i < dimM; i++) {
		for (int j = 0; j < dimN; j++) {
			ans.element[i][j] *= b;
		}
	}
	return ans;
}

Matrix Matrix::operator*(const Matrix b)
{
	Matrix ans(dimM, b.dimN);
	//循环模拟进行两矩阵相乘运算
	for (int i = 0; i < ans.dimM; i++) {
		for (int j = 0; j < ans.dimN; j++) {
			for (int k = 0; k < dimN && k < b.dimM; k++) {
				ans.element[i][j] += element[i][k] * b.element[k][j];
			}
		}
	}
	return ans;
}

void Matrix::det()
{
	if (dimM != dimN) {
		Det = 0x3f3f3f3f;
		return;
	}
	int cnt = 0;
	//高斯消元法计算行列式的值
	Matrix tee(*this);
	for (int i = 0; i < dimM - 1; i++) {
		int temp = i;
		double maxx = tee.element[i][i];
		for (int j = i + 1; j < dimM; j++) {
			if (fabs(maxx) < fabs(tee.element[j][i])) {
				maxx = tee.element[j][i];
				temp = j;
			}
		}
		if (fabs(maxx) < 0.000001) {
			Det = 0;
			break;
		}
		if (temp != i) {
			cnt++;
			for (int j = i; j < dimM; j++) {
				std::swap(tee.element[i][j], tee.element[temp][j]);
			}
		}
		for (int j = i + 1; j < dimM; j++) {
			double ans = tee.element[j][i] / tee.element[i][i];
			for (int k = i; k < dimM; k++) {
				tee.element[j][k] = tee.element[j][k] - tee.element[i][k] * ans;
			}
		}
	}
	double ans = 1;
	for (int i = 0; i < dimM; i++) {
		ans *= tee.element[i][i];
	}
	Det = !(cnt & 1) ? ans : -ans;
	return;
}

Matrix::~Matrix()
{
	for (int i = 0; i < dimM; i++) {
		delete[] element[i];
	}
	delete[] element;
}
