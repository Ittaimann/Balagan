#pragma once

#include <Containers/Array.h>
#include <Containers/String.h>
#include <stdio.h>

namespace BAL
{
class FileIo
{

public:
	enum status
	{
		OK,
		ERROR,
	};

	status OpenFile(const String i_filePath, Array<char>& o_outputBuffer);
	status CloseFile(FILE* i_fd);

private:
};

} // namespace BAL
