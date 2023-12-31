#pragma once

#include <Array.h>
#include <String.h>
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

	// TODO: nodiscard
	status openFile(const String& i_filePath, Array<char>* o_outputBuffer);
	status closeFile(FILE* i_fd);

private:
};

} // namespace BAL
