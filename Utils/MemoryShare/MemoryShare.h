#ifndef __MEMORYSHARE_H_
#define __MEMORYSHARE_H_

#include <string>
#include <Windows.h>

/*
	�̼߳�ͨ��ʹ��
*/
class MemoryShare
{
public:
	MemoryShare(const std::string & sShareName);
	~MemoryShare();

public:
	bool Write(void * pBuf, int nSize);

	// pBuf ��СΪBUF_SIZE���ڴ���Ҫ�Լ����
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
