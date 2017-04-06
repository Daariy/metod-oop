#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class WisdomItem
{
public:
	static WisdomItem* createAncestor(ifstream &ifst);
	virtual void In(ifstream &ifst) = 0;
	virtual void Out(ostream &stream) = 0;
	void WisdomItem::Writeinfo(WisdomItem &wisd, ofstream &ofst);
	void TEXT(ifstream &ifst);
	bool Compare(WisdomItem &item2);
	char* getText();
	int CountSighns(char* Text);
private:
	char _text[256];
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
	void Out(ostream &stream);

private:
	char Author[256];
};

class Poslovica :public WisdomItem
{
public:
	Poslovica() {};
	~Poslovica() {};
	void In(ifstream &ifst);
	void Out(ostream &stream);
private:
	char Country[256];
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
	void Sort();
private:
	struct node
	{
		WisdomItem* _item;
		node* _next;
	};
	node *_head, *_tail, *_current;
	int _size;
};
