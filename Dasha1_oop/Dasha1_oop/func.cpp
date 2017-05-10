#include "stdafx.h"
#include "func.h"
#include <cstring>
#include "Protect.h"

using namespace std;

WisdomItem* WisdomItem::CreateAncestor(ifstream &ifst)
{
	CheckInputFile(ifst);
	WisdomItem* newItem = nullptr;
	int num = 0;

	ifst >> num;
	CheckWrongInput(ifst);
	if (!(1 <= num && num <= 3)) 
	{
		cerr << "Error: unknown type" << endl;
		exit(1);
	}

	char t[256];
	ifst.getline(t, 256);
	CheckWrongInput(ifst);
	switch (num)
	{
		case 1:
		{
			newItem = new Aforysm;
			newItem->Text(ifst);
			break;
		}
		case 2:
		{
			newItem = new Poslovica;
			newItem->Text(ifst);
			break;
		}
		case 3:
		{

			newItem = new Riddle;
			newItem->Text(ifst);
			break;
		}
		default:
			return nullptr;
	}
	newItem->In(ifst);
	newItem->SetGrade(ifst);
	return newItem;
}
bool WisdomItem::Compare(WisdomItem &item2)
{
	return CountSighns(text) < item2.CountSighns(item2.text);
}

void WisdomItem::Out(ostream &ofst)
{
	CheckOutputFile(ofst);
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
void WisdomItem::Text(ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst.getline(text, 256);
	CheckWrongInput(ifst);
}
char* WisdomItem::GetText()
{
	return text;
}
void WisdomItem::SetGrade(ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst >> grade;
	CheckGrade(grade);
}
int WisdomItem::GetGrade()
{
	return grade;
}
void Aforysm::In(ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst.getline(author, 256);
}
void Aforysm::Out(ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Following statement is an Aforysm. Its author is: ";
	ofst << author << endl;
	ofst << "Its content: ";
}
void Poslovica::In(ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst.getline(country, 256);
}
void Poslovica::Out(ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Folowing statement is Poslovica. Its country is: ";
	ofst << country << endl;
	ofst << "Its content: ";
}
void Riddle::In(ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst.getline(answer, 256);
}
void Riddle::Out(ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Following statement is an Riddle. Its answer is: ";
	ofst << answer << endl;
	ofst << "Its content: ";
}

List::~List()
{
	this->Clear();
}
void List::Clear()
{
	while (size != 0)
	{
		node* temp = head->next;
		delete head;
		head = temp;
		--size;
	}
	head = nullptr;
	tail = nullptr;
	current = nullptr;

}

void List::Add(WisdomItem* item)
{
	++size;
	node* tmp = new node;
	tmp->item = item;
	tmp->next = head;
	current = tmp;

	if (head != nullptr)
	{
		tail->next = tmp;
		tail = tmp;
	}
	else
	{
		head = tail = tmp;
	}

}
WisdomItem* List::GetCurrentItem()
{
	return current->item;
}

void List::NextNode()
{
	current = current->next;
}
int List::Size()
{
	return size;
}


void List::Sort(int des)
{
	node *s, *ptr;
	int a, b;
	WisdomItem *temp;
	if (tail == nullptr)
	{
		return;
	}
	s = tail->next;
	while (s != tail)
	{
		ptr = s->next;
		while (ptr != tail->next)
		{
			if (ptr != tail->next)
			{
				switch (des)
				{
				case 0:
				{
					if (!s->item->Compare(*ptr->item))
					{
						temp = s->item;
						s->item = ptr->item;
						ptr->item = temp;
					}
				}
				case 1:
				{
					if (s->item->Compare(*ptr->item))
					{
						temp = s->item;
						s->item = ptr->item;
						ptr->item = temp;
					}
				}
				default:
					cout << "Wrong des in Sort function" << endl;
					break;
				}
			}
			else
			{
				break;
			}
			ptr = ptr->next;
		}
		s = s->next;
	}
}


void WisdomItem::Writeinfo(WisdomItem &wisd, ofstream &ofst)
{
	CheckOutputFile(ofst);
	wisd.Out(ofst);
	wisd.Out(cout);
	ofst << wisd.GetText() << endl;
	cout << wisd.GetText() << endl;
	ofst << "Quantity of special symbols in the folowing content: " << wisd.CountSighns(wisd.text) << endl;
	cout << "Quantity of special symbols in the folowing content: " << wisd.CountSighns(wisd.text) << endl;
}

void List::In(ifstream &ifst)
{
	CheckInputFile(ifst);
	while (!ifst.eof())
		{

			WisdomItem* newItem;
			this->Add(newItem->CreateAncestor(ifst));
		}

	ifst.close();
}

void List::Out(ofstream &ofst)
{
	CheckOutputFile(ofst);
	if (size)
	{
		ofst << "Container is filled:\n";
		cout << "Container is filled:\n";
	}
	else
	{
		ofst << "Container is empty:\n";
		cout << "Container is empty:\n";
	}

	for (int i = 0; i < this->Size(); i++)
	{
		this->NextNode();
		//this->GetCurrentItem()->Out(ofst);
		this->current->item->Writeinfo(*this->current->item, ofst);
	}
	string result = "----------------------------- \nThere are " + to_string(size) + " objects.\n";
	cout << result;
	ofst << result;

	ofst.close();
}
void WisdomItem::OutOnlyAforysm(ofstream &ofst)
{
	CheckOutputFile(ofst);
	return;
}
void WisdomItem::OutOnlyPoslovica(ofstream &ofst)
{
	CheckOutputFile(ofst);
	return;
}
void WisdomItem::OutOnlyRiddle(ofstream &ofst)
{
	CheckOutputFile(ofst);
	return;
}
void Aforysm::OutOnlyAforysm(ofstream &ofst)
{
	CheckOutputFile(ofst);

	Out(ofst);
	Out(cout);
	ofst << this->GetText() << endl;
	cout << this->GetText() << endl;
}
void List::OutOnlyAforysm(ofstream &ofst)
{
	CheckOutputFile(ofst);

	if (size)
	{
		ofst << "Container is filled:\n";
		cout << "Container is filled:\n";
	}
	else
	{
		ofst << "Container is empty:\n";
		cout << "Container is empty:\n";
	}

	for (int i = 0; i < this->Size(); i++)
	{
		this->NextNode();
		this->GetCurrentItem()->OutOnlyAforysm(ofst);

	}
	string result = "----------------------------- \nThere are " + to_string(size) + " objects.\n";
	cout << result;
	ofst << result;

	ofst.close();
}
void Poslovica::OutOnlyPoslovica(ofstream &ofst)
{
	CheckOutputFile(ofst);
	Out(ofst);
	Out(cout);
	ofst << this->GetText() << endl;
	cout << this->GetText() << endl;
}
void List::OutOnlyPoslovica(ofstream &ofst)
{
	CheckOutputFile(ofst);

	if (size)
	{
		ofst << "Container is filled:\n";
		cout << "Container is filled:\n";
	}
	else
	{
		ofst << "Container is empty:\n";
		cout << "Container is empty:\n";
	}

	for (int i = 0; i < this->Size(); i++)
	{
		this->NextNode();
		this->GetCurrentItem()->OutOnlyPoslovica(ofst);

	}
	string result = "----------------------------- \nThere are " + to_string(size) + " objects.\n";
	cout << result;
	ofst << result;

	ofst.close();

}

void Riddle::OutOnlyRiddle(ofstream &ofst)
{
	CheckOutputFile(ofst);
	Out(ofst);
	Out(cout);
	ofst << this->GetText() << endl;
	cout << this->GetText() << endl;
}

void List::OutOnlyRiddle(ofstream &ofst)
{
	CheckOutputFile(ofst);
	if (size)
	{
		ofst << "Container is filled:\n";
		cout << "Container is filled:\n";
	}
	else
	{
		ofst << "Container is empty:\n";
		cout << "Container is empty:\n";
	}

	for (int i = 0; i < this->Size(); i++)
	{
		this->NextNode();
		this->GetCurrentItem()->OutOnlyRiddle(ofst);

	}
	string result = "----------------------------- \nThere are " + to_string(size) + " objects.\n";
	cout << result;
	ofst << result;

	ofst.close();
	
}

void Aforysm::MultiMethod(WisdomItem *other, ofstream &ofst) {
	other->MMAforysm(ofst);
}

void Aforysm::MMAforysm(ofstream &ofst) {
	ofst << endl << "Aforysm and Aforysm" << endl << endl;
	cout << endl << "Aforysm and Aforysm" << endl << endl;
}

void Aforysm::MMPoslovica(ofstream &ofst) {
	ofst << endl << "Poslovica and Aforysm" << endl << endl;
	cout << endl << "Poslovica and Aforysm" << endl << endl;
}

void Aforysm::MMRiddle(ofstream &ofst) {
	ofst << endl << "Riddle and Aforysm" << endl << endl;
	cout << endl << "Riddle and Aforysm" << endl << endl;
}

void Poslovica::MultiMethod(WisdomItem *other, ofstream &ofst) {
	other->MMPoslovica(ofst);
}

void Poslovica::MMAforysm(ofstream &ofst) {
	ofst << endl << "Aforysm and Poslovica" << endl << endl;
	cout << endl << "Aforysm and Poslovica" << endl << endl;
}

void Poslovica::MMPoslovica(ofstream &ofst) {
	ofst << endl << "Poslovica and Poslovica" << endl << endl;
	cout << "Poslovica and Poslovica" << endl << endl;
}

void Poslovica::MMRiddle(ofstream &ofst) {
	ofst << endl << "Riddle and Poslovica" << endl << endl;
	cout << endl << "Riddle and Poslovica" << endl << endl;
}

void Riddle::MultiMethod(WisdomItem *other, ofstream &ofst) {
	other->MMRiddle(ofst);
}

void Riddle::MMAforysm(ofstream &ofst) {
	ofst << endl << "Aforysm and Riddle" << endl << endl;
	cout << endl << "Aforysm and Riddle" << endl << endl;
}

void Riddle::MMPoslovica(ofstream &ofst) {
	ofst << endl << "Poslovica and Riddle" << endl << endl;
	cout << endl << "Poslovica and Riddle" << endl << endl;
}

void Riddle::MMRiddle(ofstream &ofst) {
	ofst << endl << "Riddle and Riddle" << endl << endl;
	cout << endl << "Riddle and Riddle" << endl << endl;
}

// Вызов мультиметода для элементов контейнера
void List::MultiMethod(ofstream &ofst) {
	ofst << "Multimethod." << endl;
	List::node* temp = nullptr;
	for (int i = 0; i < size; i++) {
		current = current->next;
		temp = current;
		for (int j = 0; j < size; j++) {
			current->item->MultiMethod(temp->item, ofst);
			current->item->Writeinfo(*current->item, ofst);
			temp->item->Writeinfo(*temp->item, ofst);
			temp = temp->next;
		}
	}
}
