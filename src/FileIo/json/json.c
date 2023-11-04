#include <fcntl.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//#include "json.h"
typedef enum status{
    OK,
    ERROR,
} status; 

status CloseFile(FILE* i_filePtr)
{
    fclose(i_filePtr);
    return OK;
}

// technically speaking this isn't openFile as much as its get file contents
status OpenFile(const char* i_filePath, long* o_size, char** o_outputBuffer)
{
    FILE *filePtr = NULL; 
    filePtr = fopen(i_filePath,"r");
    // NEED to figure out a better way to do this
    if( filePtr == NULL )
    {
        fprintf(stdout,"error",NULL);
        return ERROR;

    }
    fseek(filePtr, 0L, SEEK_END);
    *o_size = ftell(filePtr);
    *o_outputBuffer = (char*)malloc(*o_size);

    fseek(filePtr,0,SEEK_SET);

    int ret = fread(*o_outputBuffer,*o_size,1,filePtr);
    if( ret != 1)
    {
        fprintf(stdout,"FUXK",NULL);
        return ERROR;
    }
    return CloseFile(filePtr);
}

void PrintFile(char* i_buffer, long i_size)
{
    for( int i = 0; i < i_size; i++)
    {
        printf("%c",i_buffer[i]);
    } 
}


// test main
int main() {
    const char* file = "test.txt";
    char* content = NULL;
    long size = 0;
    OpenFile(file,&size,&content);
    PrintFile(content,size);

}
