#include <iostream>

using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	Printer(string mo, string me, int a);
	~Printer();
	bool isValidPrint(int pages);
	void print(int pages);
	void showPrinter();
};

class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string mo, string me, int a, int i);
	~InkJetPrinter();
	bool isValidInkJetPrint(int pages);
	void printInkJet(int pages);
	void showInkJetPrinter();
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string mo, string me, int a, int t);
	~LaserPrinter();
	bool isValidLaserPrint(int pages);
	void printLaser(int pages);
	void showLaserPrinter();
};