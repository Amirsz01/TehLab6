#include "Train.h"

ostream& operator<<(ostream& stream, Train& obj)
{
	stream << "----------| ����� |-----------" << endl
		<< "����� ����������: " << obj.getEndPoint() << endl
		<< "����� ������: " << obj.getTrainNum() << endl
		<< "����� �����������: " << obj.getTimeStart() << endl;
	return stream;
}

Train::Train()
{
	cout << "������ ����������� Train" << endl;
	sEndPoint = "";
	sTrainNum = "";
	sTimeStart = "";
}

Train::Train(const Train& obj)
{
	cout << "������ ����������� ����������� Train" << endl;
	sEndPoint = obj.sEndPoint;
	sTrainNum = obj.sTrainNum;
	sTimeStart = obj.sTimeStart;
}

Train::~Train()
{
	cout << "������ ���������� Train" << endl;
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
