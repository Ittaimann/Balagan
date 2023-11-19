#include "String.h"
#include <cstdlib>
#include <cstring> // for strlen

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
	Append(i_string, strlen(i_string));
	CStringCopy(i_string);
}

String::~String()
{
	delete m_data;
}

void String::Append(const char* i_string, uint32 i_length)
{
	if (i_string == nullptr || i_length == 0)
	{
		return;
	}
	Resize(i_length + m_size);
}

void String::Resize(uint32 i_size)
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
char* String::Data()
{
	return m_data;
}
const char* String::Data() const
{
	return m_data;
};

void String::CStringCopy(const char* i_string)
{
	memcpy(m_data, i_string, m_size);
}

} // namespace BAL
