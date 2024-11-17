#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape() {
    next = NULL;
}


void Shape::draw() {
    cout << "Shape" << endl;
}

Shape* Shape::add(Shape* p) {
    this->next = p;
    return p;
}

Shape* Shape::getNext() {
    return next;
}

void Shape::paint() {
    draw();
}

void Shape::setNext(Shape* p) {
    this->next = p->next;
}

void Line::draw() {
    cout << "Line" << endl;
}

void Circle::draw() {
    cout << "Circle" << endl;
}

void Rect::draw() {
    cout << "Rectangle" << endl;
}
