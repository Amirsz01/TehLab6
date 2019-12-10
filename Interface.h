#pragma once
#include "Train.h"

class Interface
{
	Train *data;
	int size;
public:
	Interface();
	~Interface();
	void add();
	void del();
	void sort();
	void search();
	void print();
};