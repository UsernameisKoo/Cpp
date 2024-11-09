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
	else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
}
void Printer::showPrinter() { cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장"; }


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
			cout << "프린트하였습니다." << endl;
		}
		else {
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		}
	}
	else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
}
void InkJetPrinter::showInkJetPrinter() {
	showPrinter();
	cout << ", 남은 토너 " << availableInk << endl;
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
			cout << "프린트하였습니다." << endl;
		}
		else {
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		}
	}
	else cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
}
void LaserPrinter::showLaserPrinter() {
	showPrinter();
	cout << ", 남은 토너 " << availableToner << endl;
}

int main() {
	InkJetPrinter* ink =  new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter * laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->showInkJetPrinter();
	cout << "레이저 : ";
	laser->showLaserPrinter();

	int printer, paper;
	char ch;
	while (true) {

		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printer >> paper;
		switch (printer) {
		case 1: ink->printInkJet(paper); break;
		case 2: laser->printLaser(paper); break;
		default: break;
		}
		ink->showInkJetPrinter();
		laser->showLaserPrinter();

		cout << "게속 프린트 하시겠습니까(y/n)>>";
		cin >> ch;
		if (ch == 'n') break;
		while (ch != 'y')
		{
			cout << "게속 프린트 하시겠습니까(y/n)>>";
			cin >> ch;
			if (ch == 'n') break;
		}
	}

	delete ink;
	delete laser;
	return 0;
}