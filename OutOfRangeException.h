#pragma once
#include <iostream>


class OutOfRangeException:
	public std::exception
{
	int code;

public:

	OutOfRangeException(int p_error);

	const char* what() const noexcept;
};