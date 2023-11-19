#include "String.h"
#include <cstdlib>
#include <cstring> // for strlen

#include <vector>

namespace BAL
{

String::String()
	: m_data(nullptr)
	, m_size(0)
{
}

String::String(const char* i_string)
	: m_data(nullptr)
	, m_size(0)
{
	append(i_string, strlen(i_string));
	cStringCopy(i_string);
}

String::~String()
{
	delete m_data;
}

void String::append(const char* i_string, uint32 i_length)
{
	if (i_string == nullptr || i_length == 0)
	{
		return;
	}
	resize(i_length + m_size);
}

void String::resize(uint32 i_size)
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
char* String::data()
{
	return m_data;
}
const char* String::data() const
{
	return m_data;
};

void String::cStringCopy(const char* i_string)
{
	memcpy(m_data, i_string, m_size);
}

} // namespace BAL
