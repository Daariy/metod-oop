#include <fstream>

using namespace std;

bool FilesCmp(ifstream &expected, ifstream &actual) {
	bool flag = true;
	char ActTest;
	char ExpTest;
	while (!expected.eof()) {
		expected >> ExpTest;
		actual >> ActTest;
		if (ExpTest != ActTest) {
			flag = false;
			break;
		}
	}
	return flag;
}