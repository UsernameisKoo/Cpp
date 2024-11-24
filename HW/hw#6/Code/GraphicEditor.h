#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <vector>
#include "UI.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

class GraphicEditor {
    std::vector<Shape*> shapes;
public:
    GraphicEditor();
    ~GraphicEditor();
    void run();
    void input_new(int n);
    bool del(int n);
    void show();
};

#endif
