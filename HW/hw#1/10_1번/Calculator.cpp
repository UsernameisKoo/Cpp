#include<iostream>
using namespace std;

class Add {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};
class Sub {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};
class Mul {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};
class Div {
	int a;
	int b;
public:
	void setValue(int x, int y);
	int calculate();
};

void Add::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Add::calculate()
{
	return a + b;
}
void Sub::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Sub::calculate()
{
	return a - b;
}
void Mul::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Mul::calculate()
{
	return a * b;
}
void Div::setValue(int x, int y)
{
	a = x;
	b = y;
}
int Div::calculate()
{
	return a / b;
}


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