// Utils.cpp : 定义控制台应用程序的入口点。
//

#include "StringUtils/stringutils.h"
#include "Sqlite3/SQLiteHelper.h"
#include "MemoryShare/MemoryShare.h"

namespace utilstest {}

int main()
{
	utilstest::Test();
	utilstest::Test1();
	utilstest::Test_Sql0();
	utilstest::Test_MemoryShare0();
    return 0;
}

