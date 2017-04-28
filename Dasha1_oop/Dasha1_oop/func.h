#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class WisdomItem
{
public:
	static WisdomItem* createAncestor(ifstream &ifst);
	virtual void In(ifstream &ifst) = 0;
	virtual void Out(ostream &ofst) = 0;	
	virtual void OutOnlyAforysm(ofstream &ofst);
	virtual void OutOnlyPoslovica(ofstream &ofst);
	virtual void OutOnlyRiddle(ofstream &ofst);
	void Writeinfo(WisdomItem &wisd, ofstream &ofst);
	void TEXT(ifstream &ifst);
	bool Compare(WisdomItem &item2);
	char* getText();
	int getGrade();
	void setGrade(ifstream &ifst);
	int CountSighns(char* Text);

private:
	char _text[256];
	int _grade;
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
private:
	char Author[256];
};

class Poslovica :public WisdomItem
{
public:
	Poslovica() {};
	~Poslovica() {};
	void In(ifstream &ifst);
	void Out(ostream &ofst);
	void OutOnlyPoslovica(ofstream &ofst);
private:
	char Country[256];
};

class Riddle : public WisdomItem
{
public:
	Riddle() {};
	~Riddle() {};
	void  In(ifstream &ifst);
	void Out(ostream &ofst);
	void OutOnlyRiddle(ofstream &ofst);
private:
	char Answer[256];
};

class List
{
public:
	List() : _head(nullptr), _tail(nullptr), _current(nullptr), _size(0) {};
	~List();
	void Clear();
	void Add(WisdomItem* item);
	WisdomItem* getCurrentItem();
	void nextNode();
	int size();
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
	void Sort(int des);
	void OutOnlyAforysm(ofstream &ofst);
	void OutOnlyPoslovica(ofstream &ofst);
	void OutOnlyRiddle(ofstream &ofst);
private:
	struct node
	{
		WisdomItem* _item;
		node* _next;
	};
	node *_head, *_tail, *_current;
	int _size;
};