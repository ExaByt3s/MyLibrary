// Utils.cpp : 定义控制台应用程序的入口点。
//

#include "StringUtils/Test.h"
#include "Sqlite3/Test.h"
#include "MemoryShare/Test.h"
#include "Json/Test.h"
#include "XML/Test.h"
#include "CodeCvt/Test.h"
#include "InitFile/Test.h"
#include "CommandLineArguments/Test.h"
#include "WinRegistryKey/Test.h"
#include "WinApiCaller/Test.h"

namespace utilstest {}

int main()
{
// 	utilstest::Test_stringutils0();
// 	utilstest::Test_stringutils1();
// 	utilstest::Test_MemoryShare0();
// 	utilstest::Test_Sql0();
// 	utilstest::Test_Json();
// 	utilstest::Test_xml0();

//	utilstest::Test_codecvt0();

//	utilstest::Test_Initfile0();
	utilstest::Test_CommandLineArguments0();
//	utilstest::Test_WinRegistryKey1();
//	utilstest::Test_WinRegistryKey0();

//	utilstest::Test_WinApiCaller0();
	return 0;
}

