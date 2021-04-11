#include "Vector.h"

Vector::Vector():
		dim(0),
		length(0),
		vec(nullptr) 
{

}

Vector::~Vector() {
	delete[] vec;
}

double& Vector::operator[](int ind) const
{	
	return vec[ind];
}

std::ostream& operator<<(std::ostream& out, Vector& v)
{
	out << "Vector{";
	for (int i = 0; i < v.dim; i++) {
		out << v.vec[i];
		if (i < (v.dim - 1)) {
			out << ", ";
		}
	}
	out << "}";
	return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
	for (int i = 0; i < v.dim; i++) {
		in >> v.vec[i];
	}

	return in;
}

int Vector::getDim() const
{
	return dim;
}

double Vector::getLength() const
{
	return length;
}

Vector::Vector(int d):
	dim(d), length(0)
{
	vec = new double[dim];
	for (int i = 0; i < dim; i++) {
		vec[i] = 0;
	}
}

Vector::Vector(const Vector& v):
	dim(v.dim), length(v.length)
{
	vec = new double[dim];
	for (int i = 0; i < dim; i++) {
		vec[i] = v.vec[i];
	}
}



Vector Vector::operator+(const Vector& v) const
{
	Vector res(*this);
	for (int i = 0; i < dim; i++) {
		res.vec[i] += v.vec[i];
	}
	return res;
}

Vector Vector::operator-(const Vector& v) const
{
	Vector res(*this);
	for (int i = 0; i < dim; i++) {
		res.vec[i] -= v.vec[i];
	}
	return res;
}

Vector Vector::operator+=(Vector& v) {

	for (int i = 0; i < dim; i++) {
		vec[i] += v.vec[i];
	}

	return (*this);
}

Vector Vector::operator-=(Vector v) {

	for (int i = 0; i < dim; i++) {
		vec[i] -= v.vec[i];
	}

	return (*this);
}

 const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v) {
		return (*this);
	}
	else {
		dim = v.dim;
		length = v.length;
		for (int i = 0; i < dim; i++) {
			vec[i] = v.vec[i];
		}
	}
	return (*this);
}


Vector& Vector::operator++()
{	
	for (int i = 0; i < dim; i++) {
		vec[i]++;
	}

	return (*this);
}

Vector& Vector::operator--()
{	
	for (int i = 0; i < dim; i++) {
		vec[i]--;
	}

	return (*this);
}

Vector Vector::operator*(double a)
{	
	for (int i = 0; i < dim; i++) {
		vec[i] *= a;
	}
		
	return (*this);
}

double Vector::operator*(Vector v)
{	

	double res = 0;
	for (int i = 0; i < dim; i++) {
		res += vec[i] * v.vec[i];
	}

	return res;
}

Vector Vector::operator*(Matrix M)
{

	Vector res(dim);
	for (int i = 0; i < dim; i++) {

		for (int j = 0; j < M.jptr[i + 1] - M.jptr[i]; j++) {

			res[i] += vec[M.elemsCol[M.jptr[i] + j]] *M.elems[M.jptr[i] + j];

		}

	}

	return res;
}

Vector::operator double* ()
{
	return vec;
}


void Vector::updateLength()
{
	double s = 0;
	for (int i = 0; i < dim; i++) {
		s += (vec[i] * vec[i]);
	}
	length = sqrt(s);
}

//Вывод данных для тестов
void Vector::printdata() {
	printf("Dim = %d", dim);
	printf("\nCoordinates:\n");
	double s = 0;
	for (int i = 0; i < dim; i++) {
		printf("%lf ", vec[i]);
		s += vec[i] * vec[i];
	}

	printf("\nLength = %fl\n", sqrt(s));
}

