#pragma once
#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"
#ifndef VECTOR_H
#define VECTOR_H


class Vector {

	friend class Matrix;
	int     dim;		//Размерность вектора
	double  length;		//Длина вектора
	double* vec;		//Координаты вектора

public:

	Vector();
	Vector(int d);
	Vector(const Vector &v);
	~Vector();

	double& operator[] (int ind) const;
	Vector  operator+  (const Vector& v) const;
	Vector	operator-  (const Vector& v) const;
	Vector  operator+= (Vector& v);
	Vector  operator-= (Vector v);
	Vector  operator*  (double a);
	double  operator*  (Vector v);
	Vector  operator*  (Matrix M);
	const Vector& operator=(const Vector& v);
	Vector& operator++();
	Vector& operator--();
	operator double*();


	friend  std::ostream& operator<< (std::ostream& out, Vector& v);
	friend  std::istream& operator>> (std::istream&  in, Vector& v);

	

	void   updateLength();
	int	   getDim() const;
	double getLength() const;
	
	
	void printdata();
};

#endif