#include "OutOfRangeException.h"


OutOfRangeException::OutOfRangeException(int p_error):
	code(p_error)
{
}

const char* OutOfRangeException::what() const noexcept
{
	switch (code)
	{
	case 11:
		return "Неверное заполнен массив jptr";
	case 12:
		return "";
	case 13:
		return "";
	case 14:
		return "";
	case 15:
		return "";
	}

}

