#pragma once
class Matrix
{
public:
	double Det;
	int dimM, dimN;//�����ά�ȣ���m*n
	double **element;//��ά������Ϊ����
	Matrix();//�޲ι��캯����Ĭ�Ϲ���2000*2000ά����
	Matrix(const Matrix &b);//�������캯��
	Matrix(int m, int n);//���ι��캯��������m*nά����
	void Change();//�޸ľ����Ԫ��ֵ�������޸ģ����ڴ���������ĸ�ֵ
	void Output();//���������Ϣ���ڲ����޸ĸ�ʽ
	Matrix operator+(const Matrix b);//���ؼӷ��������ʵ��ͬά����ֱ���������
	Matrix operator*(const int b);//���س˷��������ʵ�־���ֱ����������
	Matrix operator*(const Matrix b);//���س˷��������ʵ�־���ֱ���������
	void det();//������Ϊ������������Ӧ����ʽ��ֵ
	~Matrix();//�����������ͷŶ�ά�����ڴ�
};
#include "Matrix.cpp"

