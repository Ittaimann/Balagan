#include "String.h"
#include <cstdlib>
#include <cstring> // for strlen

namespace BAL
{

String::String()
{
}

String::String(const char *i_string)
{
    Append(i_string, strlen(i_string));
}

String::~String()
{
    delete m_data;
}

void String::Append(const char *i_string, uint32 i_length)
{
    if (i_string == nullptr || i_length == 0)
    {
        return;
    }
    Resize(i_length + m_size);
}

void String::Resize(uint32 i_size)
{
    char *tempData = new char[i_size + 1];
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
}
char *String::Data()
{
    return m_data;
}

} // namespace BAL
