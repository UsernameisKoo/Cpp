#ifndef GRAPHIC_EDITOR_H
#define GRAPHIC_EDITOR_H

#include "Shape.h"

class GraphicEditor {
    int node_size;
    Shape* pStart;
    Shape* pLast;
public:
    GraphicEditor();
    void run();
    void input_new(int n);
    bool del(int n);
    void show();
};

#endif 
