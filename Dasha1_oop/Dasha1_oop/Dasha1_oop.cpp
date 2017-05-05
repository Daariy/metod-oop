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
	/*if (argc != 3)
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
		int des =0 ;
		cout << "What you want?" << endl << "0-All!" << endl << "1-OnlyAforism!" << endl << "2-OnlyPoslovica!" << endl << "3-OnlyRiddle!" << endl;
		cout << "Please, Enter number: ";
		cin >> des;
		system("cls");
		switch (des)
		{ 
			case 0:
			{
				l.Out(outputFile);
				break;
			}
			case 1:
			{
				l.OutOnlyAforysm(outputFile);
				break;

			}
			case 2:
			{
				l.OutOnlyPoslovica(outputFile);
				break;
			}
			case 3:
			{
				l.OutOnlyRiddle(outputFile);
				break;
			}
			default:
				break;
		}
		
		l.Clear();
		outputFile.open(argv[2], ios::out | ios::app);
		l.Out(outputFile);
	}
	system("Pause");
	return 0;*/
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}