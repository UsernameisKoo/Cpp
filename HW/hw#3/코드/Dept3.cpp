#include "Dept3.h"
#include<iostream>
#include<string>
using namespace std;

Dept3::Dept3(int size) {
	this->size = size;
	scores = new int[size];
}
Dept3::~Dept3() {
	delete scores;
}
int Dept3::getSize()
{
	return size;
}
void Dept3::read()
{
	cout << size << "개 점수 입력>> ";
	for (int i = 0; i < size; i++)
	{
		cin >> scores[i];
	}
}
bool Dept3::isOver60(int index)
{
	if (scores[index] >= 60)
		return true;
	else
		return false;
}
