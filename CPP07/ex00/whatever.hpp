#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include "styling.h"

using std::cout;
using std::endl;

template <class T>
T max(T &a, T &b)
{
	return ( a > b ? a : b );
}

template <class T>
T min(T &a, T &b)
{
	return ( a < b ? a : b );
}

template <class T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

#endif