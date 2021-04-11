#pragma once
#include <iostream>

class IncompatibleDimException:
	public std::exception
{
	int code;

public:

	IncompatibleDimException(int p_error);

	const char* what() const noexcept;

};

