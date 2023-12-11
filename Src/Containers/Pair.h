#pragma once

namespace BAL
{
template <typename T1, typename T2>
class Pair
{
public:
	T1 getFirst() const { return m_first; }
	T2 getSecond() const { return m_second; }
	void setFirst(const T1& i_first) { m_first = i_first; };
	void setSecond(const T2& i_second) { m_second = i_second; };

private:
	T1 m_first;
	T2 m_second;
};
} // namespace BAL
