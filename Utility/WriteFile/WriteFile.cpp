#include "WriteFile.h"
#include <cstdio>

void shaneutility::WriteFile_C(const char* filePath, const char* content, const char* mode) {
    FILE* file = fopen(filePath, mode);
    if (file != NULL) 
    {
        fputs(content, file);
        fclose(file);
    }
    else 
    {
        printf("Failed to open the file at %s\n", filePath);
    }
}