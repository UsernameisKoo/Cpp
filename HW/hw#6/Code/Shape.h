#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    Shape* next;
protected:
    virtual void draw()=0;
public:
    void paint();
};

#endif 
