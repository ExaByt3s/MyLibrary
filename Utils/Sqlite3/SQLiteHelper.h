#pragma once

#include <string>

#include "lib/sqlite3.h"  

#pragma comment(lib, "Sqlite3/lib/sqlite3.lib")

class SqlVec
{
public:
	SqlVec()
		: m_ppValue(0)
		, m_nCol(0)
		, m_nRaw(0)
	{

	}

	~SqlVec()
	{

	}

public:
	int GetRaw()
	{
		return m_nRaw;
	}

	int GetCol()
	{
		return m_nCol;
	}

	char * GetAt(int x, int y)
	{
		return m_ppValue[x * m_nCol + y];
	}

public:
	void Init(char ** ppValue, int nRaw, int nCol)
	{
		m_ppValue = ppValue;
		m_nRaw = nRaw;
		m_nCol = nCol;
	}

private:
	char ** m_ppValue;
	int		m_nRaw;
	int		m_nCol;
};

class SQLiteHelper
{
public:
	SQLiteHelper(std::string sPath);
	virtual ~SQLiteHelper();

public:
	bool	ExecSQL(const char *sql);
	bool	RawQuery(const char *sql, SqlVec & vec);
	bool	OpenDB(const char *path);
	bool	CloseDB();

	inline char *	GetErrorMsg()
	{
		return m_pErrorMessge;
	}

private:
	sqlite3 *	m_pDB;
	char *		m_pErrorMessge;
};

namespace utilstest
{
	inline void Test_Sql0()
	{
		SQLiteHelper * help = new SQLiteHelper("C:\\Users\\ydh\\Desktop\\aa\\SqlTest0");

		if (0 != help->GetErrorMsg())
		{
			delete help;
			return;
		}

		std::string sDropTable = "drop table mytable";
		help->ExecSQL(sDropTable.c_str());

		std::string temp;
		temp = "CREATE TABLE mytable (NAME TEXT NOT NULL, AGE INT NOT NULL);";
		help->ExecSQL(temp.c_str());

		temp = "insert into mytable values('µÈ´ý', 25)";
		help->ExecSQL(temp.c_str());
		temp = "select * from mytable";
		SqlVec vec;
		help->RawQuery(temp.c_str(), vec);
		delete help;
	}
}
