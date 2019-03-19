#ifndef __LIMITSINGLEINSTANCE_H_
#define __LIMITSINGLEINSTANCE_H_

#include <windows.h>

//
// 限制进程实例唯一
//

class LimitSingleInstance
{
private:
	DWORD  m_dwLastError;
	HANDLE m_hMutex;

public:
	LimitSingleInstance(LPCTSTR strInstanceUUID)
	{
		m_hMutex = ::CreateMutex(NULL, FALSE, strInstanceUUID);
		m_dwLastError = ::GetLastError();
	}

	~LimitSingleInstance()
	{
		if (m_hMutex) 
		{
			::CloseHandle(m_hMutex);
		}
	}

	BOOL IsAnotherInstanceRunning()
	{
		return (ERROR_ALREADY_EXISTS == m_dwLastError);
	}
};

#endif // LIMITSINGLEINSTANCE_H