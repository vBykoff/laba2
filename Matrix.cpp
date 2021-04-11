#include "Matrix.h"

Matrix::Matrix() :
	dim(0),
	count(0),
	elems(nullptr),
	elemsCol(nullptr),
	jptr(nullptr)
{
}

Matrix::Matrix(int p_dim, int p_count) :
	dim(p_dim),
	count(p_count)
{
	elems = new double[count];
	elemsCol = new int[count];
	jptr = new int[dim + 1];
}

Matrix::Matrix(const Matrix& M) :
	dim(M.dim),
	count(M.count)
{
	elems = new double[count];
	elemsCol = new int[count];
	jptr = new int[dim + 1];
	for (int i = 0; i < count; i++) {
		elems[i] = M.elems[i];
		elemsCol[i] = M.elemsCol[i];
	}
	for (int i = 0; i <= dim; i++) {
		jptr[i] = M.jptr[i];
	}

}

Matrix::Matrix(int p_dim, int p_count, double* p_elems, int* p_elemsCol, int* p_jptr) :
	dim(p_dim),
	count(p_count)
{
	elems = new double[count];
	elemsCol = new int[count];
	jptr = new int[dim + 1];
	for (int i = 0; i < count; i++) {
		elems[i] = p_elems[i];
		elemsCol[i] = p_elemsCol[i];
	}
	for (int i = 0; i <= dim; i++) {
		jptr[i] = p_jptr[i];
	}

}

Matrix::~Matrix()
{
	delete[] elems;
	delete[] elemsCol;
	delete[] jptr;

}

const Matrix& Matrix::operator=(const Matrix& M)
{
	if (this == &M) {
		return M;
	}
	else {
		dim = M.dim;
		count = M.count;
		for (int i = 0; i < count; i++) {
			elems[i] = M.elems[i];
			elemsCol[i] = M.elemsCol[i];
		}
		for (int i = 0; i <= dim; i++) {
			jptr[i] = M.jptr[i];
		}

	}
	return (*this);
}

const Matrix Matrix::operator*(double a) const
{
	Matrix res(*this);
	for (int i = 0; i < count; i++) {
		res.elems[i] *= a;
	}

	return res;
}



const Vector Matrix::operator* (const Vector v) const
{
	Vector res(dim);
	for (int i = 0; i < dim; i++) {

		for (int j = 0; j < jptr[i + 1] - jptr[i]; j++) {

			res[i] += v[elemsCol[jptr[i] + j]] * elems[jptr[i] + j];

		}

	}

	return res;
}

int Matrix::getDim() const
{
	return dim;
}

int Matrix::getElemsCount() const
{
	return count;
}

std::ostream& operator<<(std::ostream& out, Matrix& M)
{
	out << "Matrix:\n";
	for (int i = 0; i < M.dim; i++) {
		out << "||";
		int k = M.jptr[i];
		for (int j = 0; j < M.dim; j++) {

			if ( (j == M.elemsCol[k]) && (k < M.jptr[i + 1]) ) {
				out << "  " << M.elems[k];
				k++;
			}
			else {
				out << "  0";
			}
		}
		out << "  ||\n";
	}

	return out;
}

std::istream& operator>>(std::istream& in, Matrix& M)
{
	for (int i = 0; i < M.dim; i++) {
		in >> M.elems[i];
	}
	for (int i = 0; i < M.dim; i++) {
		in >> M.elemsCol[i];
	}
	for (int i = 0; i <= M.count; i++) {
		in >> M.jptr[i];
	}

	return in;
}
