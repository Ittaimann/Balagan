#include "../Core/CoreDefs.h"

// TODO: fill this out
namespace BAL
{

template <typename T> class Array
{
public:
	Array();
	virtual ~Array();
	T operator[](const uint32 i_index);
	T At(const uint32 i_index);
	T Front();
	T Back();
	T* Data();

private:
	T* m_data;
	uint32 m_size;
};

} // namespace BAL
