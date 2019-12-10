#include "Interface.h"

Interface::Interface()
{
	cout << "������ ����������� ������ Interface" << endl;
	data = nullptr;
	size = 0;
}

Interface::~Interface()
{
	if(data)
		delete[] data;
	cout << "������ ���������� Interface" << endl;
}

void Interface::add()
{
	string sTmp;
	string sTimeFormat;
	int iTmp;
	try
	{
		system("CLS");
		cout << "---------| ���������� |---------" << endl;
		Train *tmp = new Train[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		cout << "������� ����� ������: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"����� ������ �� ����� ���� ������";
		tmp[size].setTrainNum(sTmp);
		cout << "������� ����� �������� ������: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"����� �������� ������ �� ����� ���� ������";
		tmp[size].setEndPoint(sTmp);
		cout << "������� ����� ����������� ������:" << endl;
		cout << "���� [0-24]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 24)
			throw (string)"���� ���� ������ ���� � ��������� �� 0 �� 24!";
		sTimeFormat = sTmp;
		cout << "������ [0-60]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 60)
			throw (string)"���� ����� ������ ���� � ��������� �� 0 �� 60!";
		sTimeFormat = sTimeFormat + ":" + sTmp;
		tmp[size].setTimeStart(sTimeFormat);
		if (data)
			delete[] data;
		data = tmp;
		cout << "������� ������� ��������" << endl;
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
	cout << "---------| ���������� |---------" << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ����������";
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "�������� ������� ��� ��������: ";
		cin >> index;
		if (index < 0 || index > size-1)
			throw (string)"���������� �������� �� ����������";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "������� ������ �������" << endl;
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
		cout << "������� ������ �������" << endl;
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
	cout << "---------| ���������� |---------" << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ����������";
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (data[j].getEndPoint().compare(data[j + 1].getEndPoint()) > 0) {
					swap(data[j], data[j + 1]);// ������ �������� �������
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
	cout << "---------| ����� |---------" << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ������";
		string sTime; // �����
		string sTimeFormat; // �����
		bool empty = false; // ���� ������� ������
		int iTime;
		cout << "������� ���� [0-24]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 24)
			throw (string)"���� ���� ������ ���� � ��������� �� 0 �� 24!";
		sTimeFormat = sTime;
		cout << "������� ������ [0-60]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 60)
			throw (string)"���� ����� ������ ���� � ��������� �� 0 �� 60!";
		sTimeFormat = sTimeFormat + ":" + sTime;
		for (int i = 0; i < size; i++) {
			if (data[i].getTimeStart().compare(sTimeFormat) >= 0)
			{
				!empty ? empty = true : false;
				cout << data[i];
			}
		}
		if (!empty)
			cout << "�� ������ ������� ��� ���������� �������!" << endl;
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}

void Interface::print()
{
	system("CLS");
	cout << "---------| ����� |---------" << endl << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ������";
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
