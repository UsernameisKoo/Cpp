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
    cout << "�׷��� �������Դϴ�.\n";
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
                cout << "����Ʈ�� ��� �ֽ��ϴ�.\n";
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
            cout << "�޴��� �߸� �����ϼ̽��ϴ�.\n";
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
        cout << "�߸��� �Է��Դϴ�.\n";
        return;
    }
    shapes.push_back(newShape);
}

bool GraphicEditor::del(int n) {
    if (n < 0 || n >= shapes.size()) {
        cout << "�߸��� �ε����Դϴ�.\n";
        return false;
    }
    delete shapes[n];               
    shapes.erase(shapes.begin() + n); 
    return true;
}

void GraphicEditor::show() {
    if (shapes.empty()) {
        cout << "���� ������ �����ϴ�!!!\n";
        return;
    }
    for (int i = 0; i < shapes.size(); ++i) {
        cout << i << ": ";
        shapes[i]->paint(); 
    }
}
