#include <iostream>
#include <fstream>
//#include "func.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;

class ListTest : public ::testing::Test {
};

TEST_F(ListTest, CheckClear)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.Clear();
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListClear.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckOutAforysm)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.OutOnlyAforysm(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListOutAforysm.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckOutPoslovica)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.OutOnlyPoslovica(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListOutPoslovica.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckOutRiddle)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.OutOnlyRiddle(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListOutRiddle.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckSort1)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.Sort(1);
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListSorted1.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckSort0)
{
	ifstream ifst("ListInput.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.Sort( 0);
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListSorted0.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ListTest, CheckSortEqual)
{
	ifstream ifst("ListEqual.txt");
	ofstream ofst("ListTest.txt");

	List c;
	c.In(ifst);
	c.Sort(1);
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ListTest.txt");
	ifstream expected("ListSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

class WisdomItemTest : public ::testing::Test {
};

TEST_F(WisdomItemTest, CheckCountSighns)
{
	WisdomItem* a = new Aforysm;
	strcpy_s(a->text,"...");
	int expected = 3;
	ASSERT_EQ(expected, a->CountSighns(a->text));
}

TEST_F(WisdomItemTest, CheckCountSighnsZero)
{
	WisdomItem* a = new Aforysm;
	strcpy_s(a->text, "");
	int expected = 0;
	ASSERT_EQ(expected, a->CountSighns(a->text));
}

TEST_F(WisdomItemTest, CheckCompare)
{
	WisdomItem* s1 = new Aforysm;
	strcpy_s(s1->text, "..");

	WisdomItem* s2 = new Aforysm;
	strcpy_s(s2->text, "...");
	
	ASSERT_TRUE(s1->Compare(*s2));
}

class AforysmTest : public ::testing::Test {
};

TEST_F(AforysmTest, CheckInput)
{
	ifstream ifst("InAforysm.txt");
	Aforysm actual;
	actual.In(ifst);
	Aforysm b;
	strcpy_s(b.author,"Dasha");

	ASSERT_STREQ(actual.author, b.author);
}

TEST_F(AforysmTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	Aforysm b;
	strcpy_s(b.author,"Dasha");
	b.Out(ofst);
	ofst.close();

	ifstream expected("OutAforysm.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


class PoslovicaTest : public ::testing::Test {
};

TEST_F(PoslovicaTest, CheckInput)
{
	ifstream ifst("InPoslovica.txt");
	Poslovica actual;
	actual.In(ifst);
	Poslovica b;
	strcpy_s(b.country, "Russia");

	ASSERT_STREQ(actual.country, b.country);
}

TEST_F(PoslovicaTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	Poslovica b;
	strcpy_s(b.country, "Russia");
	b.Out(ofst);
	ofst.close();

	ifstream expected("OutPoslovica.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

class RiddleTest : public ::testing::Test {
};

TEST_F(RiddleTest, CheckInput)
{
	ifstream ifst("InRiddle.txt");
	Riddle actual;
	actual.In(ifst);
	Riddle b;
	strcpy_s(b.answer, "Dasha");

	ASSERT_STREQ(actual.answer, b.answer);
}

TEST_F(RiddleTest, CheckOutput)
{
	ofstream ofst("OutTest.txt");
	Riddle b;
	strcpy_s(b.answer, "Dasha");
	b.Out(ofst);
	ofst.close();

	ifstream expected("OutRiddle.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}
