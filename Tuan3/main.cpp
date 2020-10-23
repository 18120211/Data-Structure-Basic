#include "examinee.h"
#include "pch.h"

int main()
{
	examinee TS;
	string s;
	TS.WriteSumOfScore(TS.ReadExamineeList("data.txt"), "outFile.txt");
	system("pause");
	return 0;
}

