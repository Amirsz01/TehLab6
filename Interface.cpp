#include "Interface.h"

Interface::Interface()
{
	cout << "Вызван конструктор класса Interface" << endl;
	data = nullptr;
	size = 0;
}

Interface::~Interface()
{
	if(data)
		delete[] data;
	cout << "Вызван деструктор Interface" << endl;
}

void Interface::add()
{
	string sTmp;
	string sTimeFormat;
	int iTmp;
	try
	{
		system("CLS");
		cout << "---------| Добавление |---------" << endl;
		Train *tmp = new Train[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		cout << "Введите номер поезда: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"Номер поезда не может быть пустым";
		tmp[size].setTrainNum(sTmp);
		cout << "Введите место прибытия поезда: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"Место прибытия поезда не может быть пустым";
		tmp[size].setEndPoint(sTmp);
		cout << "Введите время отправления поезда:" << endl;
		cout << "Часы [0-24]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 24)
			throw (string)"Ввод часа должен быть в диапазоне от 0 до 24!";
		sTimeFormat = sTmp;
		cout << "Минуты [0-60]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 60)
			throw (string)"Ввод минут должен быть в диапазоне от 0 до 60!";
		sTimeFormat = sTimeFormat + ":" + sTmp;
		tmp[size].setTimeStart(sTimeFormat);
		if (data)
			delete[] data;
		data = tmp;
		cout << "Элемент успешно добавлен" << endl;
		size++;
		system("pause");
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
		system("pause");
	}
}

void Interface::del()
{
	int index;
	system("CLS");
	cout << "---------| Извлечение |---------" << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для извлечения";
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "Выберите элемент для удаления: ";
		cin >> index;
		if (index < 0 || index > size-1)
			throw (string)"Выбранного элемента не существует";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Элемент удален успешно" << endl;
			size--;
			system("pause");
			return;
		}
		Train* tmp = new Train[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
		}
		delete[] data;
		data = tmp;
		size--;
		cout << "Элемент удален успешно" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}


void Interface::sort()
{
	system("CLS");
	cout << "---------| Сортировка |---------" << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для сортировки";
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (data[j].getEndPoint().compare(data[j + 1].getEndPoint()) > 0) {
					swap(data[j], data[j + 1]);// меняем элементы местами
				}
			}
		}
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}

void Interface::search()
{
	system("CLS");
	cout << "---------| Поиск |---------" << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для поиска";
		string sTime; // Время
		string sTimeFormat; // Время
		bool empty = false; // Флаг пустоты вывода
		int iTime;
		cout << "Введите часы [0-24]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 24)
			throw (string)"Ввод часа должен быть в диапазоне от 0 до 24!";
		sTimeFormat = sTime;
		cout << "Введите минуты [0-60]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 60)
			throw (string)"Ввод минут должен быть в диапазоне от 0 до 60!";
		sTimeFormat = sTimeFormat + ":" + sTime;
		for (int i = 0; i < size; i++) {
			if (data[i].getTimeStart().compare(sTimeFormat) >= 0)
			{
				!empty ? empty = true : false;
				cout << data[i];
			}
		}
		if (!empty)
			cout << "По вашему запросу нет подходящих поездов!" << endl;
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}

void Interface::print()
{
	system("CLS");
	cout << "---------| Вывод |---------" << endl << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для вывода";
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}
