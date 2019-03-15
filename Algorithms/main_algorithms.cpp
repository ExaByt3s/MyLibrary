#include "KMP/KMPStrCmp.h"


// ÄÚ´æĞ¹Â¶¼ì²âÆ÷
#ifndef NDEBUG
#pragma comment(lib, "..//vld//release//vld.lib")
#include "..//vld//head//vld.h"
#endif

int main()
{
	int i = 0;
	//while (i < 10000)
	{
		Test1();
		Test2();
		Test3();
		Test4();
		Test5();
		++i;
	}
	
	return 1;
}