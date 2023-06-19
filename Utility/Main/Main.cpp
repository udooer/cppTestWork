#include "../WriteFile/WriteFile.h"

void writeFileTest() 
{
	shaneutility::WriteFile_C("C:\\TMP\\fileTest.txt", "hello");
	shaneutility::WriteFile_C("C:\\TMP\\fileTest.txt", " world !!");
	shaneutility::WriteFile_C("C:\\TMP\\fileTest.txt", "\nShane");
}

void WriteFileCppTest()
{
	shaneutility::WriteFile_CPP("test.txt", "hello\n");
	shaneutility::WriteFile_CPP("test.txt", L"hihihi\n");
}

int main() 
{
	//writeFileTest();
	WriteFileCppTest();
}
