#include "../WriteFile/WriteFile.h"

void writeFileTest() 
{
	shaneutility::WriteFile_C("C:\\TMP\\fileTest.txt", "hello");
	shaneutility::WriteFile_C("C:\\TMP\\fileTest.txt", " world !!");
	shaneutility::WriteFile_C("C:\\TMP\\fileTest.txt", "\nShane");
}

int main() 
{
	writeFileTest();
}