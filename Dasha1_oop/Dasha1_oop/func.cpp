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

void WisdomItem::Out(ofstream &ofst)
{
	return;
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
void Aforysm::Out(ofstream &ofst)
{

	ofst << "��� �������. ��� �����: ";
	ofst << Author << endl;
	ofst << "�������: ";
	cout << "��� �������. ��� ����� ";
	cout << Author << endl;
	cout << "�������: ";
}
void Poslovica::In(ifstream &ifst)
{
	ifst.getline(Country, 256);
}
void Poslovica::Out(ofstream &ofst)
{
	ofst << "��� ���������. ������: ";
	ofst << Country << endl;
	ofst << "���������: ";
	cout << "��� ���������. ������: ";
	cout << Country << endl;
	cout << "���������: ";
}
void WisdomItem::Writeinfo(WisdomItem &wisd, ofstream &ofst)
{
	wisd.Out(ofst);
	ofst << wisd.getText() << endl;
	cout << wisd.getText() << endl;

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
void List::nextNode()
{
	_current = _current->_next;
}
int List::size()
{
	return _size;
}
void List::In(ifstream &ifst)
{
	if (ifst.fail())
	{
		cout << "������: �� ������� ������� ������� ����!" << endl;
		return;
	}
	else
	{
		while (!ifst.eof())
		{
			//������� ����������� �����
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
		cout << "������: �� ������� ������� �������� ����!" << endl;
		return;
	}
	else
	{
		if (_size)
		{
			ofst << "��������� ��������:\n";
			cout << "��������� ��������:\n";
		}
		else
		{
			ofst << "��������� ����\n";
			cout << "��������� ����\n";
		}

		for (int i = 0; i < this->size(); i++)
		{
			this->nextNode();
			this->_current->_item->Writeinfo(*this->_current->_item, ofst);


		}
		string result = "----------------------------- \n������� " + to_string(_size) + " �������(��).\n";
		cout << result;
		ofst << result;

		ofst.close();
	}
}