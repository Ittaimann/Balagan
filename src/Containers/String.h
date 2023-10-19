#pragma once
#include "../Core/CoreDefs.h"

namespace BAL
{
class String
{
  public:
    String();
    String(const char *i_string);
    virtual ~String();
    char *operator[](int i_index);
    void operator+(char i_char);
    void operator+(String i_string);
    void Append(const char *i_char, uint32 i_length);
    void Resize(uint32 i_size);
    char *Data();

  private:
    char *m_data;
    uint32 m_size;
};

} // namespace BAL
