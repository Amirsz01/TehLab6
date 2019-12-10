#include "Train.h"

ostream& operator<<(ostream& stream, Train& obj)
{
	stream << "----------| Поезд |-----------" << endl
		<< "Пункт назначения: " << obj.getEndPoint() << endl
		<< "Номер поезда: " << obj.getTrainNum() << endl
		<< "Время отправления: " << obj.getTimeStart() << endl;
	return stream;
}

Train::Train()
{
	cout << "Вызван конструктор Train" << endl;
	sEndPoint = "";
	sTrainNum = "";
	sTimeStart = "";
}

Train::Train(const Train& obj)
{
	cout << "Вызван конструктор копирования Train" << endl;
	sEndPoint = obj.sEndPoint;
	sTrainNum = obj.sTrainNum;
	sTimeStart = obj.sTimeStart;
}

Train::~Train()
{
	cout << "Вызван деструктор Train" << endl;
}

void Train::setEndPoint(string _sEndPoint)
{
	sEndPoint = _sEndPoint;
}

void Train::setTrainNum(string _sTrainNum)
{
	sTrainNum = _sTrainNum;
}

void Train::setTimeStart(string _sTimeStart)
{
	sTimeStart = _sTimeStart;
}

string Train::getEndPoint()
{
	return sEndPoint;
}

string Train::getTrainNum()
{
	return sTrainNum;
}

string Train::getTimeStart()
{
	return sTimeStart;
}
