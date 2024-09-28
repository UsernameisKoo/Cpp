#include<iostream>
using namespace std;

#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

int main(void)
{
	Add a;
	Sub s;
	Mul m;
	int x, y;
	char op;
	Div d;

	while (1)
	{
		cout << "두 정수와 연산자를 입력하세요 >> ";
		cin >> x >> y >> op;
		switch (op)
		{
		case('+'):
		{
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		}
		case('-'):
		{
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		}
		case('*'):
		{
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		}
		case('/'):
		{
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		}
		}

	}
}