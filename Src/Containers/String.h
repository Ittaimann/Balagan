#pragma once
#include "../Core/CoreDefs.h"
#include <cstdlib>
#include <cstring> // for strlen

namespace BAL
{
class String
{
public:
	String()
		: m_data(nullptr)
		, m_size(0)
	{
	}

	String(const char* i_string)
		: m_data(nullptr)
		, m_size(0)
	{
		append(i_string, strlen(i_string));
		cStringCopy(i_string);
	}

	virtual ~String() { delete m_data; }
	char* operator[](int i_index);
	void operator+(char i_char);
	void operator+(String i_string);

	void append(const char* i_cString, uint32 i_length)
	{
		if (i_cString == nullptr || i_length == 0)
		{
			return;
		}
		resize(i_length + m_size);
	}

	void resize(uint32 i_size)
	{
		char* tempData = new char[i_size + 1];
		if (m_data != nullptr)
		{
			for (uint32 i = 0; i < m_size; i++)
			{
				tempData[i] = m_data[i];
			}
			tempData[i_size + 1] = '\0';
			delete m_data;
		}
		m_data = tempData;
		m_size = i_size;
	}

	char* data() { return m_data; }
	const char* data() const { return m_data; };

private:
	void cStringCopy(const char* i_string) { memcpy(m_data, i_string, m_size); }

	char* m_data;
	uint32 m_size;
};

} // namespace BAL
