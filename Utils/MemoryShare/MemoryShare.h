#ifndef __MEMORYSHARE_H_
#define __MEMORYSHARE_H_

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

#endif
