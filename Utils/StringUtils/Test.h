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
		bool b = strwildcard("΢��", "*ע", true);
		b = 0 != strstr("΢��", "΢��", true);
	}
}
