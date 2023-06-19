#include "WriteFile.h"
#include <cstdio>
#include <fstream>
#include <iostream>

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

void shaneutility::WriteFile_CPP(const std::string& filePath, const std::string& content) 
{
    std::fstream file;
    file.open(filePath, std::fstream::out | std::fstream::app);

    if (file.is_open()) 
    {
        file << content;
        file.close();
    }
}

void shaneutility::WriteFile_CPP(const std::string& filePath, const std::wstring& content)
{
    std::wfstream file;
    file.open(filePath, std::wfstream::out | std::wfstream::app);

    if (file.is_open()) 
    {
        file << content;
        file.close();
    }
}

void shaneutility::ReadFile_CPP(const std::string& filePath) 
{
    std::fstream file;
    file.open(filePath, std::fstream::in);

    if (file.is_open()) 
    {
        std::string line;
        while (std::getline(file, line)) 
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
}

void shaneutility::WReadFile_CPP(const std::string& filePath)
{
    std::wfstream file;
    file.open(filePath, std::wfstream::in);

    if (file.is_open()) 
    {
        std::wstring line;
        while (std::getline(file, line)) 
        {
            std::wcout << line << std::endl;
        }
        file.close();
    }
}