// Dasha1_oop.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "fstream"
#include "func.h"
#include "gtest/gtest.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Error: Input and/or output filenames are missing" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream inputFile(argv[1], ios::in | ios::_Nocreate);
		l.In(inputFile);
		ofstream outputFile(argv[2], ios::out | ios::trunc);
		l.MultiMethod(outputFile);
	}
	system("Pause");
	return 0;
	/*::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
}