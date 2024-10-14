#include "Dept1.h"
#include<iostream>
#include<string>
using namespace std;

Dept1::Dept1(int size) {
	this->size = size;
	scores = new int[size];
}
Dept1::Dept1(const Dept1& dept)
{
	this->size = dept.size;
	this->scores = new int[size];
	for (int i = 0; i < size; i++) {
		scores[i] = dept.scores[i];
	}
}
Dept1::~Dept1() {
	delete [] scores;
}
int Dept1::getSize()
{
	return size;
}
void Dept1::read()
{
	cout << size << "개 점수 입력>> ";
	for (int i = 0; i < size; i++)
	{
		cin >> scores[i];
	}
}
bool Dept1::isOver60(int index)
{
	if (scores[index] >= 60)
		return true;
	else
		return false;
}
