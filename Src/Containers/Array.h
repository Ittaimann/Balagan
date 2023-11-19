#include "../Core/CoreDefs.h"

// TODO: fill this out
namespace BAL
{

template <typename T> class Array
{
public:
	Array();
	virtual ~Array();
	T operator[](const uint32 i_index)
	{
		return m_data[i_index];
	}
	T At(const uint32 i_index)
	{
		// TODO: error checking
		// TODO: uh is this correct?
		return m_data[i_index];
	}
	T Front();
	T Back();
	T* Data()
	{
		return m_data;
	}
	void Resize(uint32 i_size)
	{
	}

	uint32 Size()
	{
		return m_size;
	}

private:
	T* m_data;
	uint32 m_size;
};

} // namespace BAL
