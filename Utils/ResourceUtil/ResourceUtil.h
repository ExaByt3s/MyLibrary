#ifndef __RESOURCERUIL_H_
#define __RESOURCERUIL_H_

#include <string>
#include <windows.h>

namespace resourceutil
{
	// �ͷ���Դ�ļ�
	// hModule �� ģ����������wWinMain( _In_ HINSTANCE hInstance,...) ��hInstance
	// resourceId
	// resourceType
	// target �� ����·��
	bool ReleaseResource(HMODULE hModule, unsigned int resourceId, const std::wstring& resourceType, const std::wstring& target);
}

#endif

