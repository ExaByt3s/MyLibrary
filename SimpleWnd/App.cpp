#include "App.h"
#include "RegistStyle.h"
#include "WinBase.h"
#include "SimpleWnd.h"

#define REGIST(WndClass, StyleClass)					\
StyleClass registStyle;									\
registStyle.SetClassName(WndClass::GetWndClassName());	\
registStyle.SetIns(_hIns);								\
registStyle.SetWndProc(WinBase::_WndProc);				\
registStyle.Regist();

#define UNREGIST(WndClass, StyleClass)					\
StyleClass registStyle;									\
registStyle.SetClassName(WndClass::GetWndClassName());	\
registStyle.SetIns(_hIns);								\
registStyle.UnRegist();

App::App()
	: _hIns(0)
{
}

App::~App()
{
}

void App::RegistAllWnd()
{
	REGIST(SimpleWnd, SimpleRegistStyle);
}

void App::UnRegistAllWnd()
{
	UNREGIST(SimpleWnd, SimpleRegistStyle);
}
