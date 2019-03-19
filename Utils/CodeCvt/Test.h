#pragma once

#include "CodeCvt.h"

namespace utilstest
{
	using namespace codecvt;

	static void Test_codecvt0()
	{
		char sAnsiCode[]		=	"ABC����";		// ANSI(GBK)����				41 42 43 d3 eb bb f2 b7 c7 00
		wchar_t wsAnsiCode[]	=	L"ABC����";		// Unicode��UTF-16������		41 00 42 00 43 00 0e 4e 16 62 5e 97 00 00

		// ANSI  ת Unicode
		std::wstring wsRes = L"";
		ANSIToUTF16(sAnsiCode, wsRes);

		// Unicode ת ANSI 
		std::string sRes = "";
		UTF16ToANSI(wsAnsiCode, sRes);

		// תUTF-8
		std::string sResU8 = "";
		UTF16ToUTF8(wsAnsiCode, sResU8);

		// UTF-8 ת 16
		std::wstring wsRes16 = L"";
		UTF8ToUTF16(sResU8, wsRes16);
	}

}

