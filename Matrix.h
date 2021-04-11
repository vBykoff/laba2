#pragma once
#include <iostream>
#include <cmath>
#include "Vector.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"
#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
	friend class Vector;
	int dim;				//�����������
	int count;				//���-�� ��������� ���������
	double* elems;			//��������
	int* elemsCol;			//����� ������� �������� �� elems
	int* jptr;				//������ ���������, ����������� � ������ ������ � elems ���������� ����� ������

public:

	Matrix();
	Matrix(int p_dim, int p_count);
	Matrix(const Matrix& M);
	Matrix(int p_dim, int p_count, double* p_elems, int* p_elemsCol, int* p_jptr);
	~Matrix();



	const Matrix& operator=(const Matrix& M);
	const Matrix operator*(double a) const;


	const Vector operator* (const Vector v) const;

	friend std::ostream& operator<<(std::ostream& out, Matrix& M);
	friend std::istream& operator>>(std::istream&  in, Matrix& M);
	int getDim() const;
	int getElemsCount() const;
};
#endif
