// Dasha1_oop.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "fstream"
#include "func.h"

using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error: Input and/or output filenames are missing" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream inputFile(argv[1], ios::in | ios::_Nocreate);
		l.In(inputFile);
		ofstream outputFile(argv[2], ios::out | ios::trunc);
		l.Out(outputFile);
		l.Clear();
		outputFile.open(argv[2], ios::out | ios::app);
		l.Out(outputFile);
	}
	system("Pause");
	return 0;
}