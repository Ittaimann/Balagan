#pragma once
#include "../Core/CoreDefs.h"
#include <cstdlib>
#include <cstring> // for strlen
#include <iterator>

// TODO:
// massively clean up and reduce the nonsense in this file
// start creating an inline fo thie most likely
//... follow the cpp ref style and get it to be an iterator
namespace BAL
{
class String
{
public:
	//------------------------------------------------------------
	// Constructors
	//------------------------------------------------------------
	String()
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
	}

	virtual ~String()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
	}

	String(const char* i_cString)
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
		cStringCopy(i_cString);
	}

	String(const String& i_string)
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
		resize(i_string.size());
		for (uint i = 0; i < i_string.size(); i++)
		{
			m_data[i] = i_string[i];
		}
	}

	//------------------------------------------------------------
	// Operators
	//------------------------------------------------------------
	char operator[](int i_index) const { return at(i_index); };
	char operator[](uint i_index) const { return at(i_index); };

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
	void operator+=(const char* i_char) { append(i_char, static_cast<uint>(strlen(i_char))); }
	void operator+=(const String& i_string) { append(i_string); }

	//------------------------------------------------------------
	// append
	//------------------------------------------------------------
	void append(const char* i_cString, uint32 i_length)
	{
		if (i_cString == nullptr || i_length == 0)
		{
			return;
		}
		if (i_length == 1)
		{
			resize(m_size + 1, *i_cString);
		}
		else
		{
			const uint preResize = m_size;
			resize(i_length + m_size);
			for (uint i = 0; i < m_size - preResize; i++)
			{
				m_data[preResize + i] = i_cString[i];
			}
		}
	}

	void append(const String& i_string) { append(i_string.data(), i_string.size()); }
	void append(const char i_char) { append(&i_char, 1); }

	//------------------------------------------------------------
	// resize
	//------------------------------------------------------------
	void resize(uint32 i_size, char i_initChar)
	{
		// capcity used more or less as a tracking for the null terminator
		m_capacity = i_size + 1;
		char* tempData = allocateMem(m_capacity);
		// copy prexisting data
		if (i_size >= m_size)
		{
			stringCopy(tempData, m_data, m_size);
			for (uint sizeDif = m_size; sizeDif < i_size; sizeDif++)
			{
				tempData[sizeDif] = i_initChar;
			}
		}
		else
		{
			stringCopy(tempData, m_data, i_size);
		}

		// For those keeping track... indexes start at 0 and I'm foolish for
		// making these mistakes a lot
		tempData[i_size] = '\0';
		m_data = tempData;
		m_size = i_size;
	}

	void resize(uint32 i_size) { resize(i_size, '\0'); }

	//------------------------------------------------------------
	// data
	//------------------------------------------------------------
	char* data() { return m_data; }
	const char* data() const { return m_data; };

	//------------------------------------------------------------
	// size
	//------------------------------------------------------------
	inline uint size() const { return m_size; };

	//------------------------------------------------------------
	// at
	//------------------------------------------------------------
	const char& at(const uint i) const
	{
		// TODO: bounds check asserts
		return m_data[i];
	}
	const char& at(const int i) const
	{
		// TODO: bounds check asserts
		return m_data[i];
	}
	char& at(const uint i)
	{
		// TODO: bounds check asserts
		return m_data[i];
	}
	char& at(const int i)
	{
		// TODO: bounds check asserts
		return m_data[i];
	}

private:
	//------------------------------------------------------------
	// memory allocation
	//------------------------------------------------------------
	char* allocateMem(const uint i_size) { return new char[i_size]; }

	//------------------------------------------------------------
	// private copies
	//------------------------------------------------------------
	void stringCopy(char* i_dest, char* i_source, const uint i_size)
	{
		// TODO: add an assert when you have those
		if (i_source != nullptr && i_dest != nullptr)
		{
			for (uint i = 0; i < i_size; i++)
			{
				i_dest[i] = i_source[i];
			}
		}
	}

	void cStringCopy(const char* i_string)
	{
		const uint stringSize = static_cast<uint>(strlen(i_string));

		resize(stringSize);
		memcpy(m_data, i_string, m_size);
	}

	char* m_data;
	uint32 m_size;
	uint32 m_capacity;
};

} // namespace BAL
