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

	virtual ~String() { delete[] m_data; }
	char operator[](int i_index) const { return m_data[i_index]; };
	void operator+(char i_char);
	void operator+(String i_string);

	bool operator==(const String& i_otherString)
	{
		// strcmp might be better tbh
		if (i_otherString.size() != m_size)
		{
			return false;
		}
		else
		{
			for (uint i = 0; i < m_size; i++)
			{
				if (i_otherString[i] != m_data[i])
				{
					return false;
				}
			}
		}
		return true;
	}
	void operator+=(char i_char) { append(&i_char, 1); }
	void operator+=(String i_string) { append(i_string); }

	void append(const char* i_cString, uint32 i_length)
	{
		if (i_cString == nullptr || i_length == 0)
		{
			return;
		}
		const uint32 preResize = m_size;
		resize(i_length + m_size);
		for (uint32 i = 0; i < i_length; i++)
		{
			// TODO: unit test this code path...
			m_data[i + preResize] = i_cString[i];
		}
	}

	void append(const String i_string) { append(i_string.data(), i_string.size()); }

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

	uint size() const { return m_size; };

private:
	void cStringCopy(const char* i_string) { memcpy(m_data, i_string, m_size); }

	char* m_data;
	uint32 m_size;
};

} // namespace BAL
