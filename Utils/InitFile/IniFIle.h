#ifndef __INITFILE_H_
#define __INITFILE_H_


/*/////////////////////////////////////////////////////////////////////////

windows ini 文件的读写等

/////////////////////////////////////////////////////////////////////////*/

#include <string>

class IniFile
{
public:
	~IniFile();

	/*
		创建一个实例
		@param sPath 文件路径
		@param bAlwaysCreate 文件不存在时是否自动创建，文件不存在时如果为false，返回0，否则自动创建文件
		@return 返回实例对象，需自己释放内存
	*/
	static IniFile * CreateObj(std::string sPath, bool bAlwaysCreate = false);

	/*
		增删改查
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
