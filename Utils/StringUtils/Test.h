#pragma once

#include "stringutils.h"

namespace utilstest
{
	using namespace stringutils;

	static void Test_stringutils0()
	{
		strwildcard("cabcd", "*a", true);
	}

	static void Test_stringutils1()
	{
		bool b = strwildcard("н╒пе", "*в╒", true);
		b = 0 != strstr("н╒пе", "н╒пе", true);
	}
}
