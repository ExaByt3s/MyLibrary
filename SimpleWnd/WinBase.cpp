#include "WinBase.h"

WinBase::WinBase()
{
}

WinBase::~WinBase()
{
}

LRESULT WinBase::_OnEvent(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
	{
		::PostQuitMessage(0);
	}
	break;
	case WM_CREATE:
	{
		int i = 0;
		++i;
	}
	break;
	case WM_MOUSEMOVE:
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
			break;
		default:
			break;
		}
	}
	break;
	case WM_KEYUP:
		break;
	default:
		return  DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return  S_OK;
}

LRESULT WinBase::_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// ���ʵ�ж��󣬴������¼�
	WinBase* pThis = (WinBase*)GetWindowLong(hWnd, GWL_USERDATA);

	if (pThis)
	{
		return pThis->_OnEvent(hWnd, msg, wParam, lParam);
	}

	if (WM_CREATE == msg)
	{
		/* 
			���ڴ�����ʱ���lParam��ȡ��ʵ�ж���ָ�룬�����õ�userdata��
			lParam��CreateWindowEx�������һ�������������ģ�ֻ��WM_CREATE
			�¼�����Ӧ
		*/
		CREATESTRUCT*   pCreate = (CREATESTRUCT*)lParam;
		SetWindowLong(hWnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);

		// ��WM_CREATE��Ϣ�׸���һ����Ϣѭ��
		return SendMessage(hWnd, msg, wParam, lParam);
	}

	return  DefWindowProc(hWnd, msg, wParam, lParam);
}
