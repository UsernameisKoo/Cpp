#pragma once
#ifndef DEPT3_H
#define DEPT3_H

class Dept3 {
	int size;
	int* scores;
public:
	Dept3(int size);
	~Dept3();
	int getSize();
	void read();
	bool isOver60(int index);
};

#endif