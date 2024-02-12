#pragma once
#include <CoreDefs.h>
#include <iostream>

namespace BAL
{
template <typename T1, typename T2>
class Pair
{
public:
	Pair()
		: m_first()
		, m_second(){};
	Pair(T1 i_fist, T2 i_second)
		: m_first(i_fist)
		, m_second(i_second){};

	//	~Pair()
	//	{
	//		uint lmao = 0;
	//		std::cout << lmao;
	//	};

	Pair(const Pair& i_otherPair)
	{
		m_first = i_otherPair.getFirst();
		m_second = i_otherPair.getSecond();
	}
	Pair& operator=(const Pair& i_otherPair)
	{
		m_first = i_otherPair.getFirst();
		m_second = i_otherPair.getSecond();
		return *this;
	}

	T1 getFirst() const { return m_first; }
	T2 getSecond() const { return m_second; }
	void setFirst(const T1& i_first) { m_first = i_first; };
	void setSecond(const T2& i_second) { m_second = i_second; };

private:
	T1 m_first;
	T2 m_second;
};
} // namespace BAL
