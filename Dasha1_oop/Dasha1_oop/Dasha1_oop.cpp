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
		cerr << "Error: Input and/or output filenames are missing" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream inputFile(argv[1]);
		l.In(inputFile);
		l.Sort();
		ofstream outputFile(argv[2]);
		l.Out(outputFile);
		l.Clear();
		l.Out(outputFile);
	}
	system("Pause");
	return 0;
}

