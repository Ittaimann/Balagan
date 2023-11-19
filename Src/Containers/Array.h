#pragma once
#include "../Core/CoreDefs.h"

// TODO: fill this out
namespace BAL
{

template <typename T> class Array
{
public:
	Array(){};
	virtual ~Array()
	{
		delete m_data;
	};
	T operator[](const uint32 i_index)
	{
		return m_data[i_index];
	}
	T at(const uint32 i_index)
	{
		return m_data[i_index];
	}
	T front();
	T back();
	T* data()
	{
		return m_data;
	}
	void resize(const uint32 i_size)
	{
		if (i_size < m_size)
		{
			expand(i_size);
		}
		else
		{
			shrink(i_size);
		}
	}

	uint32 size()
	{
		return m_size;
	}

private:
	void expand(const uint32 i_size)
	{
		char* tempData = m_data;

		if (m_data != nullptr)
		{
			for (uint32 i = 0; i < m_size; i++)
			{
				tempData[i] = m_data[i];
			}
			delete m_data;
		}
		else
		{
			m_data = allocate(i_size);
		}

		m_data = tempData;
		m_size = i_size;
	}

	void shrink(const uint32 i_size)
	{
		char* tempData = allocate(i_size);
		// assert if Data is sub that size
		for (uint32 i = 0; i < i_size; i++)
		{
			tempData[i] = m_data[i];
		}
		delete m_data;
		m_data = tempData;
		m_size = i_size;
		m_capacity = i_size;
	}

	T* allocate(const uint32 i_size)
	{
		return new T[i_size];
	}

	T* m_data;
	uint32 m_size;
	uint32 m_capacity;
};

} // namespace BAL
