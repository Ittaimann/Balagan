#pragma once
#include "../Core/CoreDefs.h"

// TODO:
// - move constructors
// - refernce type vs pointer type vs all the types
// - solidify when I am allocating, anytime we allocate its a seperate thing from the state setting
// - allocators
namespace BAL
{

template <typename T>
class Array
{

	static constexpr uint32 C_GROWTH_RATE = 2u;

public:
	//---- constructors -----
	Array()
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0){};
	virtual ~Array()
	{
		delete[] m_data;
		m_size = 0;
		m_data = nullptr;
	};

	//---- accessors ----
	T& operator[](const uint32 i_index) const { return m_data[i_index]; }
	T& at(const uint32 i_index) const { return m_data[i_index]; }
	T& front() { return m_data[0]; }
	T& back() { return m_data[m_size - 1]; }
	const T& front() const { return m_data[0]; }
	const T& back() const { return m_data[m_size - 1]; }
	T* data() { return m_data; }

	//---- modifiers -----
	void clear() { shrink(0); }
	void resize(const uint32 i_size)
	{
		if (i_size > m_size)
		{
			expand(i_size);
			m_size = m_capacity; // here as re"size" should adjust size
		}
		else
		{
			shrink(i_size);
		}
	}

	void push_back(const T& i_value)
	{
		append();
		// placement new?
		T* newObj = &m_data[m_size - 1];
		new (newObj) T(i_value);
	}

	T& push_back()
	{
		append();
		m_data[m_size] = new T;
		return m_data[m_size];
	}

	//---- getters -----
	uint32 size() const { return m_size; }
	uint32 capacity() const { return m_capacity; }

private:
	void expand(const uint32 i_size)
	{
		T* tempData = allocate(i_size);
		if (m_data != nullptr)
		{
			for (uint32 i = 0; i < m_size; i++)
			{
				tempData[i] = m_data[i];
			}
			delete m_data;
			m_data = tempData;
		}
		else
		{
			m_data = tempData;
		}

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
			expand(m_size + 1);
			m_size += 1;
		}
	}

	void shrink(const uint32 i_size)
	{
		T* tempData = allocate(i_size);
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
