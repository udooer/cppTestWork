#pragma once 
#include <string>
namespace shaneutility {
	void WriteFile_C(const char* filePath, const char* content, const char* mode = "a");

	void WriteFile_CPP(const std::string& filePath, const std::string& content);

	void WriteFile_CPP(const std::string& filePath, const std::wstring& content);

	void ReadFile_CPP(const std::string& filePath);

	void WReadFile_CPP(const std::string& filePath);
}