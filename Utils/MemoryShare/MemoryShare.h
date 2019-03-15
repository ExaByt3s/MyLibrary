#pragma once

#include <string>
#include <Windows.h>

/*
	线程间通信使用
*/
class MemoryShare
{
public:
	MemoryShare(const std::string & sShareName);
	~MemoryShare();

public:
	bool Write(void * pBuf, int nSize);

	// pBuf 大小为BUF_SIZE，内存需要自己解决
	bool Read(void * pBuf);

	bool Clear();

	bool IsReadToWrite();

	bool IsReadToRead();

	int GetBuffSize();

private:
	HANDLE  m_hMapFile;
	LPVOID	m_lpBase;
};

namespace utilstest
{
	static void Test_MemoryShare0()
	{
		MemoryShare mem("{822E85B1-73D3-4F4C-A02D-15B846007A56}");
		char buffw[] = "test for MemoryShare";

		if (mem.IsReadToWrite())
		{
			mem.Write(buffw, sizeof(buffw));
		}

		char buffr[255] ={ 0 };

		if (mem.IsReadToRead())
		{
			mem.Read(buffr);
		}
	}
	static void Test_MemoryShare1()
	{
		MemoryShare mem("{822E85B1-73D3-4F4C-A02D-15B846007A56}");
		char buffw[] = "test for MemoryShare";

		char buffr[255] ={ 0 };

		if (mem.IsReadToRead())
		{
			mem.Read(buffr);
		}

		if (mem.IsReadToWrite())
		{
			mem.Write(buffw, sizeof(buffw));
		}

		
	}

}