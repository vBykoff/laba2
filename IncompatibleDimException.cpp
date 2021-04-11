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
		return "����������� ������� �� ��������� � ������������ �������";
	case 22:
		return "������ ������� �� ������������� ����������� �������";
	case 23:
		return "����� �� ������� ������� ��������� �������";
	case 24:
		return "����������� �������� �� ���������";
	case 25:
		return "";
	default:
		return "";
	}
    
}
