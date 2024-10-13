#include "Dept1.h"
#include<iostream>
#include<string>
using namespace std;

int countPass(Dept1 dept)
{
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++)
	{
		if (dept.isOver60(i))
			count++;
	}
	return count;
}

int main(void)
{
	Dept1 com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}
// 10 20 30 40 50 60 70 80 90 100