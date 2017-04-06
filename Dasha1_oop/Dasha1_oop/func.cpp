#include "stdafx.h"
#include "func.h"
using namespace std;

WisdomItem* WisdomItem::createAncestor(ifstream &ifst)
{
	WisdomItem* newItem = nullptr;
	int num = 0;

	ifst >> num;
	char t[256];
	ifst.getline(t, 256);
	switch (num)
	{
	case 1:
	{
		newItem = new Aforysm;
		newItem->TEXT(ifst);
		break;
	}
	case 2:
	{

		newItem = new Poslovica;
		newItem->TEXT(ifst);
		break;
	}
	default:
	{
		return nullptr;
	}
	}
	newItem->In(ifst);
	return newItem;

}
bool WisdomItem::Compare(WisdomItem &item2)
{
	return CountSighns(_text) < item2.CountSighns(item2._text);
}

void WisdomItem::Out(ostream &stream)
{
	return;
}
int WisdomItem::CountSighns(char* text)
{
	char c;
	int count = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		c = text[i];
		if (c == ',' || c == '.' || c == '?' || c == '!')
		{
			count++;
		}
	}

	return count;

}
void WisdomItem::TEXT(ifstream &ifst)
{
	ifst.getline(_text, 256);
}
char* WisdomItem::getText()
{
	return _text;
}
void Aforysm::In(ifstream &ifst)
{
	ifst.getline(Author, 256);
}
void Aforysm::Out(ostream &stream)
{

	stream << "Following statement is an Aforysm. Its Author is: ";
	stream << Author << endl;
	stream << "Its content: ";

}
void Poslovica::In(ifstream &ifst)
{
	ifst.getline(Country, 256);
}
void Poslovica::Out(ostream &stream)
{
	stream << "Folowing statement is Poslovica. Its Country is: ";
	stream << Country << endl;
	stream << "Its content: ";

}

List::~List()
{
	this->Clear();
}
void List::Clear()
{
	while (_size != 0)
	{
		node* temp = _head->_next;
		delete _head;
		_head = temp;
		--_size;
	}
	_head = nullptr;
	_tail = nullptr;
	_current = nullptr;

}

void List::Add(WisdomItem* item)
{
	++_size;
	node* tmp = new node;
	tmp->_item = item;
	tmp->_next = _head;
	_current = tmp;

	if (_head != nullptr)
	{
		_tail->_next = tmp;
		_tail = tmp;
	}
	else
	{
		_head = _tail = tmp;
	}

}

WisdomItem* List::getCurrentItem()
{

	return _current->_item;
}

void List::nextNode()
{
	_current = _current->_next;
}
int List::size()
{
	return _size;
}

void List::Sort()
{
	node *s, *ptr;
	int a, b;
	WisdomItem *temp;
	if (_tail == nullptr)
	{
		return;
	}
	s = _tail->_next;
	while (s != _tail)
	{
		ptr = s->_next;
		while (ptr != _tail->_next)
		{
			if (ptr != _tail->_next)
			{

				if (!s->_item->Compare(*ptr->_item))
				{
					temp = s->_item;
					s->_item = ptr->_item;
					ptr->_item = temp;
				}
			}
			else
			{
				break;
			}
			ptr = ptr->_next;
		}
		s = s->_next;
	}
}


void WisdomItem::Writeinfo(WisdomItem &wisd, ofstream &ofst)
{
	wisd.Out(ofst);
	wisd.Out(cout);
	ofst << wisd.getText() << endl;
	cout << wisd.getText() << endl;
	ofst << "Quantity of special symbols in the folowing content: " << wisd.CountSighns(wisd._text) << endl;
	cout << "Quantity of special symbols in the folowing content: " << wisd.CountSighns(wisd._text) << endl;
}
void List::In(ifstream &ifst)
{
	if (ifst.fail())
	{
		cerr << "Error: Unable to open input file" << endl;
		return;
	}
	else
	{
		while (!ifst.eof())
		{

			WisdomItem* newItem;
			this->Add(newItem->createAncestor(ifst));
		}
	}

	ifst.close();
}

void List::Out(ofstream &ofst)
{

	if (ofst.fail())
	{
		cerr << "Error: Unable to open output file" << endl;
		return;
	}
	else
	{
		if (_size)
		{
			ofst << "Container is filled:\n";
			cout << "Container is filled:\n";
		}
		else
		{
			ofst << "Container is empty:\n";
			cout << "Container is empty:\n";
		}

		for (int i = 0; i < this->size(); i++)
		{
			this->nextNode();
			this->_current->_item->Writeinfo(*this->_current->_item, ofst);
		}

		string result = "----------------------------- \nThere are " + to_string(_size) + " objects.\n";
		cout << result;
		ofst << result;

		ofst.close();
	}
}