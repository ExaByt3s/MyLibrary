#include "Heap.h"

template<class T>
Heap<T>::Heap(std::function<bool(const T&, const T&)> cmpFun)
	: m_cmpfun(cmpFun)
{
}

template<class T>
Heap<T>::~Heap()
{

}

template<class T>
void Heap<T>::insert(T value)
{
	m_values.push_back(value);
	up(m_values.size() - 1);
}

template<class T>
void Heap<T>::remove(int nIndex)
{
	swap(m_values[m_values.size() - 1], m_values[nIndex]);
	m_values.pop_back();
	adjust(nIndex, m_values.size());
}

template<class T>
void Heap<T>::up(int nIndex)
{
	if (0 == nIndex)
	{
		return;
	}

	int nParentIndex = (nIndex - 1) / 2;

	if (!m_cmpfun(m_values[nParentIndex], m_values[nIndex]))
	{
		swap(m_values[nParentIndex], m_values[nIndex]);
		up(nParentIndex);
	}
}

template<class T>
void Heap<T>::adjust(int nIndex, int nLen)
{
	if (nIndex >= nLen)
	{
		return;
	}

	int nLeftIndex = 2 * nIndex + 1;
	int nRightIndex = nLeftIndex + 1;
	int nChangeIndex = nIndex;

	if (nLeftIndex < nLen && !m_cmpfun(m_values[nIndex], m_values[nLeftIndex]))
	{
		if (nRightIndex < nLen && !m_cmpfun(m_values[nLeftIndex], m_values[nRightIndex]))
		{
			// right
			nChangeIndex = nRightIndex;
		}
		else
		{
			// left
			nChangeIndex = nLeftIndex;
		}
	}
	else if (nRightIndex < nLen && !m_cmpfun(m_values[nIndex], m_values[nRightIndex]))
	{
		// right
		nChangeIndex = nRightIndex;
	}

	if (nChangeIndex != nIndex)
	{
		swap(m_values[nIndex], m_values[nChangeIndex]);
		adjust(nChangeIndex, nLen);
	}
}

template<class T>
void Heap<T>::build()
{
	for (int i = m_values.size() / 2; i > 0; --i)
	{
		adjust(i, m_values.size());
	}
}
