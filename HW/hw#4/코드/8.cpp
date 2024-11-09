#include <iostream>
#include "8.h"
using namespace std;

Printer::Printer(string mo = "", string me = "", int a = 0) {
	this->model = mo;
	this->manufacturer = me;
	this->availableCount = a;
	this->printedCount = 0;
}
Printer::~Printer(){}
bool Printer::isValidPrint(int pages) {
	if (availableCount > pages) return true;
	else return false;
}
void Printer::print(int pages) {
	if (isValidPrint(pages)) {
		printedCount += pages;
		availableCount -= pages;
	}
	else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
}
void Printer::showPrinter() { cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��"; }


InkJetPrinter::InkJetPrinter(string mo = "", string me = "", int a = 0, int i = 0) : Printer(mo, me, a) { this->availableInk = i; }
InkJetPrinter::~InkJetPrinter() {};
bool InkJetPrinter::isValidInkJetPrint(int pages) {
	if (availableInk > pages) return true;
	else return false;
}
void InkJetPrinter::printInkJet(int pages) {
	if (isValidPrint(pages)) {
		if (isValidInkJetPrint(pages)) {
			print(pages);
			availableInk -= pages;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
		else {
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
	}
	else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
}
void InkJetPrinter::showInkJetPrinter() {
	showPrinter();
	cout << ", ���� ��� " << availableInk << endl;
}

LaserPrinter::LaserPrinter(string mo = "", string me = "", int a = 0, int t = 0) : Printer(mo, me, a) { this->availableToner = t; }
LaserPrinter::~LaserPrinter() {};
bool LaserPrinter::isValidLaserPrint(int pages) {
	if (availableToner > pages) return true;
	else return false;
}
void LaserPrinter::printLaser(int pages) {
	if (isValidPrint(pages)) {
		if (isValidLaserPrint(pages)) {
			print(pages);
			availableToner -= pages;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
		else {
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		}
	}
	else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
}
void LaserPrinter::showLaserPrinter() {
	showPrinter();
	cout << ", ���� ��� " << availableToner << endl;
}

int main() {
	InkJetPrinter* ink =  new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter * laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	ink->showInkJetPrinter();
	cout << "������ : ";
	laser->showLaserPrinter();

	int printer, paper;
	char ch;
	while (true) {

		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink->printInkJet(paper); break;
		case 2: laser->printLaser(paper); break;
		default: break;
		}
		ink->showInkJetPrinter();
		laser->showLaserPrinter();

		cout << "�Լ� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		while (ch != 'y')
		{
			cout << "�Լ� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
			cin >> ch;
			if (ch == 'n') break;
		}
	}

	delete ink;
	delete laser;
	return 0;
}