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
		ofstream outputFile(argv[2]);
		int des =0 ;
		cout << "What you want?" << endl << "0-All!" << endl << "1-OnlyAforism!" << endl << "2-OnlyPoslovica!" << endl;
		cout << "Please, Enter number: ";
		cin >> des;
		system("cls");
		if (des== 0)
		{
			l.Out(outputFile);
		}
		if (des==1)
		{
			l.OutOnlyAforysm(outputFile);
		}
		if (des==2)
		{
			l.OutOnlyPoslovica(outputFile);
		}
		l.Clear();
		l.Out(outputFile);
	}

	system("Pause");
	return 0;
}

