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
		ifstream inputFile(argv[1], ios::in | ios::_Nocreate);
		l.In(inputFile);
		l.Sort();
		ofstream outputFile(argv[2], ios::out | ios::trunc);
		int des =0 ;
		cout << "What you want?" << endl << "0-All!" << endl << "1-OnlyAforism!" << endl << "2-OnlyPoslovica!" << endl << "3-OnlyRiddle!" << endl;
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
		if (des==3)
		{
			l.OutOnlyRiddle(outputFile);
		}
		l.Clear();
		outputFile.open(argv[2], ios::out | ios::app);
		l.Out(outputFile);
	}
	system("Pause");
	return 0;
}