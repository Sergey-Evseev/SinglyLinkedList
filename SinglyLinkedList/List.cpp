#include "List.h"

List::List()
{
	Head = Tail = NULL; //Изначально список пуст
	Count = 0;
}

List::~List()
{
	DelAll(); //Вызов функции удаления
}

void List::Add(char data)
{
	Element* temp = new Element; //создание нового элемента
	temp->data = data; //заполнение данными
	temp->Next = NULL; //следующий элемент отсутствует
	if (Head != NULL) {//новый элемент становится последним элементом списка если он не первый добавленный
		Tail->Next = temp;
		Tail = temp;
	}	
	else { //новый элемент становится единственным если он первый добавленный
		Head = Tail = temp;
	}
	Count++;
}

void List::Del()
{
	Element* temp = Head; //запоминаем адрес головного элемента
	Head = Head->Next; //перебрасываем голову на следующий элемент
	delete temp; //удаляем бывший головной элемент
}

void List::DelAll()
{	
	while (Head != 0) //Пока еще есть элементы
		Del(); //Удаляем элементы по одному
}

void List::Print()
{
	Element* temp = Head; //запоминаем адрес головного элемента
	while (temp != 0) //Пока еще есть элементы
	{		
		cout << temp->data << " "; //Выводим данные
		temp = temp->Next; //Переходим на следующий элемент
	}
	cout << "\n";
}

int List::GetCount()
{
	return Count; //Возвращаем количество элементов
}

//метод добавления элементов//из двусвязного списка
void List::Insert(int pos)
{
	//if (pos == 0) //если параметр отсутствует или равен 0, то запрашиваем его
	//{
	//	cout << "Input position: ";
	//	cin >> pos;
	//}
	//if (pos < 1 || pos > Count + 1) //Позиция от 1 до Count?
	//{
	//	cout << "Incorrect position !!!\n"; //Неверная позиция   
	//	return;
	//}
	//if (pos == Count + 1) //Если вставка в конец списка
	//{
	//	int data; //Вставляемые данные
	//	cout << "Input new number: ";
	//	cin >> data;
	//	Add(data); //Добавление в конец списка
	//	return;
	//}
	//else if (pos == 1)
	//{
	//	int data; //Вставляемые данные
	//	cout << "Input new number: ";
	//	cin >> data; //Добавление в начало списка		
	//	Add(data);
	//	return;
	//}	
	
	Element* newNode = new Element; //создание нового элемента
	cout << "Input new number: ";
	cin >> newNode->data;
	Element* temp = Head; //врем. элемент для поиска предшествующего вставляемому
	for (int i = 2; i < pos; i++)
	{
		if (temp->Next != NULL)
		{
			temp = temp->Next; //доходим до последнего элемента - если поз. 3 то до 2-го
		}		
	}
	newNode->Next = temp->Next; //указатель нового теперь равен указателю последнего
	temp->Next = newNode; //меняем местами указатели temp (указывает на последний) и нового
	Count++;	
} //конец метода вставки элементов//
