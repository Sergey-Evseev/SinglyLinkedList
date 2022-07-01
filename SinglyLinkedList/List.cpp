#include "List.h"

List::List()
{
	Head = Tail = NULL; //���������� ������ ����
	Count = 0;
}

List::~List()
{
	DelAll(); //����� ������� ��������
}

void List::Add(char data)
{
	Element* temp = new Element; //�������� ������ ��������
	temp->data = data; //���������� �������
	temp->Next = NULL; //��������� ������� �����������
	if (Head != NULL) {//����� ������� ���������� ��������� ��������� ������ ���� �� �� ������ �����������
		Tail->Next = temp;
		Tail = temp;
	}	
	else { //����� ������� ���������� ������������ ���� �� ������ �����������
		Head = Tail = temp;
	}
}

void List::Del()
{
	Element* temp = Head; //���������� ����� ��������� ��������
	Head = Head->Next; //������������� ������ �� ��������� �������
	delete temp; //������� ������ �������� �������
}

void List::DelAll()
{	
	while (Head != 0) //���� ��� ���� ��������
		Del(); //������� �������� �� ������
}

void List::Print()
{
	Element* temp = Head; //���������� ����� ��������� ��������
	while (temp != 0) //���� ��� ���� ��������
	{		
		cout << temp->data << " "; //������� ������
		temp = temp->Next; //��������� �� ��������� �������
	}
	cout << "\n";
}

int List::GetCount()
{
	return Count; //���������� ���������� ���������
}

//����� ���������� ���������//�� ����������� ������
void List::Insert(int pos)
{
	if (pos == 0) //���� �������� ����������� ��� ����� 0, �� ����������� ���
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > Count + 1) //������� �� 1 �� Count?
	{
		cout << "Incorrect position !!!\n"; //�������� �������   
		return;
	}
	if (pos == Count + 1) //���� ������� � ����� ������
	{
		int data; //����������� ������
		cout << "Input new number: ";
		cin >> data;
		Add(data); //���������� � ����� ������
		return;
	}
	else if (pos == 1)
	{
		int data; //����������� ������
		cout << "Input new number: ";
		cin >> data; //���������� � ������ ������		
		Add(data);
		return;

	}
	int i = 1; //�������
	Element* Ins = Head; //����������� �� ������ n - 1 ���������
	while (i < pos)
	{
		Ins = Ins->Next; //������� �� ��������, ����� ������� �����������
		i++;
	}
	Element* PrevIns = Ins->Prev; //������� �� ��������, ������� ������������
	Element* temp = new Element; //������� ����� �������
	//������ ������
	cout << "Input new number: ";
	cin >> temp->data;
	if (PrevIns != 0 && Count != 1) //��������� ������
		PrevIns->Next = temp;
	temp->Next = Ins;
	temp->Prev = PrevIns;
	Ins->Prev = temp;
	Count++;
} //����� ������ ���������� ���������//
