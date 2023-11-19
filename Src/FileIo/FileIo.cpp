#include "FileIo.h"

#include <CoreDefs.h>

namespace BAL
{

FileIo::status FileIo::OpenFile(String i_filePath, Array<char>& o_outputBuffer)
{
	FILE* fd = nullptr;
	fd = fopen(i_filePath.Data(), "r");

	if (fd == nullptr)
	{
		// TODO: figure out logging lmao
		return ERROR;
	}

	fseek(fd, 0L, SEEK_END);
	uint32 fileSize = ftell(fd);
	o_outputBuffer.Resize(fileSize);

	fseek(fd, 0, SEEK_SET);

	int ret = fread(o_outputBuffer.Data(), o_outputBuffer.Size(), 1, fd);

	if (ret != 1)
	{
		// NEED LOGGING
		return ERROR;
	}
	return CloseFile(fd);
}
FileIo::status FileIo::CloseFile(FILE* i_fd)
{
	fclose(i_fd);
	return OK;
}
} // namespace BAL
