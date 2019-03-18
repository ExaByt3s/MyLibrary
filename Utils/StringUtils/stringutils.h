#ifndef STRING_UTILS_H
#define STRING_UTILS_H

namespace stringutils
{
	int    strncmp(const char* s, const char* find, int n, bool icase);
	int    strcmp(const char* s, const char* find, bool icase);
	bool   strendof(const char* s, const char* find, bool icase);
	bool   strbegof(const char* s, const char* find, bool icase);
	char * strstr(const char* s, const char* find, bool icase);
	bool   strwildcard(const char* s, const char* find, bool icase);
}

#endif 
