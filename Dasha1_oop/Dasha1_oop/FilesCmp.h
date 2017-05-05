#include <fstream>

using namespace std;

bool FilesCmp(ifstream &expected, ifstream &actual) 
{
	bool flag = true;
	char actTest;
	char expTest;
	while (!expected.eof()) 
	{
		expected >> expTest;
		actual >> actTest;
		if (expTest != actTest) 
		{
			flag = false;
			break;
		}
	}
	return flag;
}