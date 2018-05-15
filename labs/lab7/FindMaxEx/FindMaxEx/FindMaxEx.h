#pragma once
#include "stdafx.h"

template <typename T, class Less>
bool FindMaxEx(vector<T> const & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}
	try
	{
		T tmpMaxValue = arr[0];
		for (T const & element : arr)
		{
			if (less(tmpMaxValue, element))
			{
				tmpMaxValue = element;
			}
		}
		maxValue = tmpMaxValue;
		return true;
	}
	catch(...) {}
}