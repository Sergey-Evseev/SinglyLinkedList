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
