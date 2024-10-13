#ifndef DEPT1_H
#define DEPT1_H

class Dept1 {
	int size;
	int* scores;
public:
	Dept1(int size);
	Dept1(const Dept1& dept);
	~Dept1();
	int getSize();
	void read();
	bool isOver60(int index);
};

#endif