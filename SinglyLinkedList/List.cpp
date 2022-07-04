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
	Count++;
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
	//if (pos == 0) //���� �������� ����������� ��� ����� 0, �� ����������� ���
	//{
	//	cout << "Input position: ";
	//	cin >> pos;
	//}
	//if (pos < 1 || pos > Count + 1) //������� �� 1 �� Count?
	//{
	//	cout << "Incorrect position !!!\n"; //�������� �������   
	//	return;
	//}
	//if (pos == Count + 1) //���� ������� � ����� ������
	//{
	//	int data; //����������� ������
	//	cout << "Input new number: ";
	//	cin >> data;
	//	Add(data); //���������� � ����� ������
	//	return;
	//}
	//else if (pos == 1)
	//{
	//	int data; //����������� ������
	//	cout << "Input new number: ";
	//	cin >> data; //���������� � ������ ������		
	//	Add(data);
	//	return;
	//}	
	
	Element* newNode = new Element; //�������� ������ ��������
	cout << "Input new number: ";
	cin >> newNode->data;
	Element* temp = Head; //����. ������� ��� ������ ��������������� ������������
	for (int i = 2; i < pos; i++)
	{
		if (temp->Next != NULL)
		{
			temp = temp->Next; //������� �� ���������� �������� - ���� ���. 3 �� �� 2-��
		}		
	}
	newNode->Next = temp->Next; //��������� ������ ������ ����� ��������� ����������
	temp->Next = newNode; //������ ������� ��������� temp (��������� �� ���������) � ������
	Count++;	
} //����� ������ ������� ���������//
