#pragma once
#include "../Core/CoreDefs.h"

// TODO: fill this out
namespace BAL
{

template <typename T>
class Array
{

	static constexpr uint32 C_GROWTH_RATE = 2u;

public:
	Array()
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0){};
	virtual ~Array() { delete m_data; };
	T operator[](const uint32 i_index) const { return m_data[i_index]; }
	T at(const uint32 i_index) const { return m_data[i_index]; }
	T front();
	T back();
	T* data() { return m_data; }
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

	void push_back(T i_value)
	{
		append(i_value);
		m_data[m_size] = i_value;
	}

	T& push_back()
	{
		append();
		return m_data[m_size];
	}
	uint32 size() const { return m_size; }
	uint32 capacity() const { return m_capacity; }

private:
	void expand(const uint32 i_size)
	{
		T* tempData = m_data;

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
		m_capacity = i_size;
	}

	void append()
	{
		if (m_size != m_capacity)
		{
			m_size += 1;
		}
		else
		{
			expand(m_size * C_GROWTH_RATE);
			m_size += 1;
		}
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

	T* allocate(const uint32 i_size) { return new T[i_size]; }

	T* m_data;
	uint32 m_size;
	uint32 m_capacity;
};

} // namespace BAL
