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
	T At(const uint32 i_index)
	{
		return m_data[i_index];
	}
	T Front();
	T Back();
	T* Data()
	{
		return m_data;
	}
	void Resize(const uint32 i_size)
	{
		if (i_size < m_size)
		{
			Expand(i_size);
		}
		else
		{
			Shrink(i_size);
		}
	}

	uint32 Size()
	{
		return m_size;
	}

private:
	void Expand(const uint32 i_size)
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
			m_data = Allocate(i_size);
		}

		m_data = tempData;
		m_size = i_size;
	}

	void Shrink(const uint32 i_size)
	{
		char* tempData = Allocate(i_size);
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

	T* Allocate(const uint32 i_size)
	{
		return new T[i_size];
	}

	T* m_data;
	uint32 m_size;
	uint32 m_capacity;
};

} // namespace BAL
