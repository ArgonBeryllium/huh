#pragma once
#include <exception>
#include <iostream>

// basic string exception
struct strex
{
	const char* msg;
	strex(const char* msg_ = "uninitialised exception message", bool auto_print = true)
	{
		if(auto_print)
			std::cerr << "StrEx: " << msg_ << std::endl;
	}

	const char* what() const throw() { return msg; }
};
