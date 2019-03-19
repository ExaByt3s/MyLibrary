#ifndef __INITFILE_H_
#define __INITFILE_H_


/*/////////////////////////////////////////////////////////////////////////

windows ini �ļ��Ķ�д��

/////////////////////////////////////////////////////////////////////////*/

#include <string>

class IniFile
{
public:
	~IniFile();

	/*
		����һ��ʵ��
		@param sPath �ļ�·��
		@param bAlwaysCreate �ļ�������ʱ�Ƿ��Զ��������ļ�������ʱ���Ϊfalse������0�������Զ������ļ�
		@return ����ʵ���������Լ��ͷ��ڴ�
	*/
	static IniFile * CreateObj(std::string sPath, bool bAlwaysCreate = false);

	/*
		��ɾ�Ĳ�
	*/
	bool AddKey(const char * sSection, const char *  sKey, const char *  sValue);
	bool DelKey(const char *  sSection, const char *  sKey);
	bool DelSection(const char *  sSection);
	bool ChangKey(const char *  sSection, const char *  sKey, const char *  sValue);
	std::string GetKey(const char *  sSection, const char *  sKey);

private:
	IniFile(std::string sPath);

private:
	std::string	m_sFileFullPath;
};

#endif
