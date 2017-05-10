#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class WisdomItem
{
public:
	static WisdomItem* CreateAncestor(ifstream &ifst);
	virtual void In(ifstream &ifst) = 0;
	virtual void Out(ostream &ofst) = 0;	
	virtual void OutOnlyAforysm(ofstream &ofst);
	virtual void OutOnlyPoslovica(ofstream &ofst);
	virtual void OutOnlyRiddle(ofstream &ofst);
	void Writeinfo(WisdomItem &wisd, ofstream &ofst);
	void Text(ifstream &ifst);
	bool Compare(WisdomItem &item2);
	char* GetText();
	int GetGrade();
	void SetGrade(ifstream &ifst);
	int CountSighns(char* Text);
	char text[256];
	int grade;
	virtual void MultiMethod(WisdomItem *other, ofstream &ofst) = 0;
	virtual void MMAforysm(ofstream &ofst) = 0;
	virtual void MMPoslovica(ofstream &ofst) = 0;
	virtual void MMRiddle(ofstream &ofst) = 0;
protected:
	WisdomItem() {};
	virtual ~WisdomItem() {};
};

class Aforysm : public WisdomItem
{
public:
	Aforysm() {};
	~Aforysm() {};
	void  In(ifstream &ifst);
	void Out(ostream &ofst);
	void OutOnlyAforysm(ofstream &ofst);
	void MultiMethod(WisdomItem *other, ofstream &ofst);
	void MMAforysm(ofstream &ofst);
	void MMPoslovica(ofstream &ofst);
	void MMRiddle(ofstream &ofst);
	char author[256];
};

class Poslovica :public WisdomItem
{
public:
	Poslovica() {};
	~Poslovica() {};
	void In(ifstream &ifst);
	void Out(ostream &ofst);
	void OutOnlyPoslovica(ofstream &ofst);
	void MultiMethod(WisdomItem *other, ofstream &ofst);
	void MMAforysm(ofstream &ofst);
	void MMPoslovica(ofstream &ofst);
	void MMRiddle(ofstream &ofst);
	char country[256];
};

class Riddle : public WisdomItem
{
public:
	Riddle() {};
	~Riddle() {};
	void  In(ifstream &ifst);
	void Out(ostream &ofst);
	void OutOnlyRiddle(ofstream &ofst);
	void MultiMethod(WisdomItem *other, ofstream &ofst);
	void MMAforysm(ofstream &ofst);
	void MMPoslovica(ofstream &ofst);
	void MMRiddle(ofstream &ofst);
	char answer[256];
};

class List
{
public:
	List() : head(nullptr), tail(nullptr), current(nullptr), size(0) {};
	~List();
	void Clear();
	void Add(WisdomItem* item);
	WisdomItem* GetCurrentItem();
	void NextNode();
	int Size();
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
	void Sort(int des);
	void OutOnlyAforysm(ofstream &ofst);
	void OutOnlyPoslovica(ofstream &ofst);
	void OutOnlyRiddle(ofstream &ofst);
	void MultiMethod(ofstream &ofst);
private:
	struct node
	{
		WisdomItem* item;
		node* next;
	};
	node *head, *tail, *current;
	int size;
};