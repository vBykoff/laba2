#include "IncompatibleDimException.h"


IncompatibleDimException::IncompatibleDimException(int p_error):
    code(p_error)
{

}

const char* IncompatibleDimException::what() const noexcept
{

	switch (code)
	{
	case 21:
		return "–азмерность матрицы не совпадает с размерностью вектора";
	case 22:
		return "ƒлинна массива не соответствует размерности матрицы";
	case 23:
		return "¬ыход за пределы массива координат вектора";
	case 24:
		return "–азмерности векторов не совпадают";
	case 25:
		return "";
	default:
		return "";
	}
    
}
