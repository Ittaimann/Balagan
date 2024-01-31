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

	virtual ~String()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
		m_size = 0;
	}

	explicit String(const char* i_cString)
		: m_data(nullptr)
		, m_size(0)
	{
		cStringCopy(i_cString);
	}

	explicit String(const String& i_string)
		: m_data(nullptr)
		, m_size(0)
	{
		resize(i_string.size());
		for (uint i = 0; i < i_string.size(); i++)
		{
			m_data[i] = i_string[i];
		}
	}

	char operator[](int i_index) const { return m_data[i_index]; };
	void operator+(char i_char);
	void operator+(String i_string);

	String& operator=(const String& i_string)
	{
		resize(i_string.size());
		for (uint i = 0; i < i_string.size(); i++)
		{
			m_data[i] = i_string[i];
		}
		return *this;
	}
	String& operator=(const char* i_string)
	{
		cStringCopy(i_string);
		return *this;
	}

	String& operator=(char i_char)
	{
		resize(1, i_char);
		return *this;
	}

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

	bool operator==(const char* i_char)
	{
		if (strlen(i_char) == 0 && m_size == 0)
		{
			return true;
		}
		return strcmp(m_data, i_char) == 0;
	}
	bool operator==(const char i_char)
	{
		if (m_size > 1)
			return false;
		else
			return m_data[0] == i_char;
	}
	void operator+=(char i_char) { append(&i_char, 1); }
	void operator+=(const String& i_string) { append(i_string); }

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

	void append(const String& i_string) { append(i_string.data(), i_string.size()); }

	void resize(uint32 i_size, char i_initChar)
	{
		char* tempData = new char[i_size + 1];
		if (m_data != nullptr)
		{
			uint i = 0;
			while (i <= i_size)
			{
				if (i < m_size)
				{
					tempData[i] = m_data[i];
				}
				else
				{
					tempData[i] = i_initChar;
				}
				i++;
			}
			delete m_data;
		}
		else
		{
			uint i = 0;
			while (i < i_size)
			{
				tempData[i] = i_initChar;
				i++;
			}
		}
		tempData[i_size + 1] = '\0';
		m_data = tempData;
		m_size = i_size;
	}

	void resize(uint32 i_size) { resize(i_size, '\0'); }

	char* data() { return m_data; }
	const char* data() const { return m_data; };

	uint size() const { return m_size; };

private:
	void cStringCopy(const char* i_string)
	{
		const uint stringSize = strlen(i_string);

		resize(stringSize);
		memcpy(m_data, i_string, m_size);
	}
	char* m_data;
	uint32 m_size;
};

} // namespace BAL
