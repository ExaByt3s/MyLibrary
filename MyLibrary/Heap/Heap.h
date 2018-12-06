#pragma once

#include <functional>
#include <vector>

template<class T>
class Heap
{
public:
	Heap(std::function<bool(const T &, const T &)> cmpFun);
	~Heap();

public:
	void insert(T value);
	void remove(int nIndex);

	inline int getsize()
	{
		return m_values.size();
	}

	inline T gettop()
	{
		if (0 == m_values.size())
		{
			throw std::exception();
		}

		return m_values[0];
	}

private:
	void up(int nIndex);
	void adjust(int nIndex, int nLen);
	void build();

private:
	// ��һ����:���ڵ㣬�ڶ�������:�ӽڵ�
	// �󶥶ѷ���t1 >= t2
	// С���ѷ���t1 <= t2
	std::function<bool(const T & t1, const T & t2)>	m_cmpfun;
	std::vector<T>	m_values;
};

