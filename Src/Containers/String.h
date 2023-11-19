#pragma once
#include "../Core/CoreDefs.h"

namespace BAL
{
class String
{
public:
	String();
	String(const char* i_string);
	virtual ~String();
	char* operator[](int i_index);
	void operator+(char i_char);
	void operator+(String i_string);
	void append(const char* i_char, uint32 i_length);
	void resize(uint32 i_size);
	char* data();
	const char* data() const;

private:
	void cStringCopy(const char* i_string);
	char* m_data;
	uint32 m_size;
};

} // namespace BAL
