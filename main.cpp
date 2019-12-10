#include <iostream>
#include <fstream>
#include "Interface.h"
/*
1. Стандартные потоки
Определить класс с именем TRAIN, содержащий следующие поля:
● название пункта назначения;
● номер поезда;
● время отправления.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа TRAIN.
Заранее число объектов не известно.

Написать программу, выполняющую следующие действия:
● записи должны быть размещены в алфавитном порядке по названиям
пунктов назначения;
● вывод на экран информации о поездах, отправляющихся после
введенного с клавиатуры времени;
● если таких поездов нет, выдать на дисплей соответствующее
сообщение.


2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и определяет, сколько в нем слов,
состоящих не более чем из четырех букв.
*/
int getWords();

int main()
{
	setlocale(LC_ALL, "Russian");
	Interface Table;
	char menu;
	int iCount;
	do
	{
		system("cls");
		cout << "----------| МЕНЮ |----------" << endl;
		cout << "1. Добавить поезд" << endl
			<< "2. Извлечь поезд" << endl
			<< "3. Сортировать поезда по алфавиту" << endl
			<< "4. Вывести список поездов" << endl
			<< "5. Поиск поездов по времени" << endl
			<< "6. Сосчитать кол-во слов в файле" << endl
			<< "0. Выход" << endl
			<< "Выбор: ";
		cin >> menu;
		if (!(cin.peek() == '\n' || cin.peek() == EOF))
		{
			cin.ignore(INT_MAX, '\n');
			cout << "[Error] Введите пункт меню в пределах [0-4]" << endl;
			system("pause");
			continue;
		}
		cin.ignore(INT_MAX, '\n');
		switch (menu)
		{
		case '1':
			Table.add();
			break;
		case '2':
			Table.del();
			break;
		case '3':
			Table.sort();
			break;
		case '4':
			Table.print();
			break;
		case '5':
			Table.search();
			break;
		case '6':
			iCount = getWords();
			if(!(iCount == -1))
				cout << "Число слов : " << iCount << endl;
			break;
		case '0':
			return 0;
		default:
			cout << "[Error] Введите пункт меню в пределах [0-4]" << endl;
			break;
		}
		system("pause");
	} while (true);
	system("pause");
	return 0;
}

int getWords()
{
	try
	{
		ifstream file("Text.txt");
		int wordsCount = 0;
		int lengthWord;
		string word;
		if (!file)
			throw (string)"Ошибка открытия файла";
		while (!file.eof())
		{
			file >> word;
			lengthWord = 0;
			for (int i = 0; i < word.length(); i++)
				if (word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z' || word[i] >= 'а' && word[i] <= 'я' || word[i] >= 'А' && word[i] <= 'Я')
					lengthWord++;
			if (lengthWord < 5 && lengthWord)
				wordsCount++;
		}
		return wordsCount;
	}
	catch (string err)
	{
		cout << "[Error] " + err << endl;
		return -1;
	}
}
