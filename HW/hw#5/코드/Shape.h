#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    Shape* next;
protected:
    virtual void draw();
public:
    Shape();
    virtual ~Shape() {}
    Shape* add(Shape* p);
    Shape* getNext();
    void paint();
    void setNext(Shape* p);
};

class Line : public Shape {
public:
    virtual void draw();
};

class Circle : public Shape {
public:
    virtual void draw();
};

class Rect : public Shape {
public:
    virtual void draw();
};

#endif 
