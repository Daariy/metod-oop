// Dasha1_oop.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "fstream"
#include "func.h"
using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	if (argc != 3)
	{
		cout << "Ошибка: входной и/или выходной файл отсутствует!" << endl;
		return 0;
	}
	else
	{
		List l;
		ifstream inputFile(argv[1]);
		l.In(inputFile);
		ofstream outputFile(argv[2]);
		l.Out(outputFile);
		l.Clear();
		l.Out(outputFile);
	}
	system("pause");
	return 0;
}


