#include "GraphicEditor.h"
#include <iostream>
using namespace std;

GraphicEditor::GraphicEditor() {}

GraphicEditor::~GraphicEditor() {
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

void GraphicEditor::run() {
    cout << "그래픽 에디터입니다.\n";
    while (true) {
        int num = UI::show_menu();
        switch (num) {
        case 1: {
            num = UI::input_shape();
            input_new(num);
            break;
        }
        case 2: {
            if (shapes.empty()) {
                cout << "리스트가 비어 있습니다.\n";
                break;
            }
            num = UI::del_index();
            del(num);
            break;
        }
        case 3: {
            show();
            break;
        }
        case 4: {
            exit(1);
        }
        default:
            cout << "메뉴를 잘못 선택하셨습니다.\n";
        }
    }
}

void GraphicEditor::input_new(int n) {
    Shape* newShape = nullptr;
    switch (n) {
    case 1:
        newShape = new Line();
        break;
    case 2:
        newShape = new Circle();
        break;
    case 3:
        newShape = new Rect();
        break;
    default:
        cout << "잘못된 입력입니다.\n";
        return;
    }
    shapes.push_back(newShape);
}

bool GraphicEditor::del(int n) {
    if (n < 0 || n >= shapes.size()) {
        cout << "잘못된 인덱스입니다.\n";
        return false;
    }
    delete shapes[n];               
    shapes.erase(shapes.begin() + n); 
    return true;
}

void GraphicEditor::show() {
    if (shapes.empty()) {
        cout << "남은 도형이 없습니다!!!\n";
        return;
    }
    for (int i = 0; i < shapes.size(); ++i) {
        cout << i << ": ";
        shapes[i]->paint(); 
    }
}
