#include "GraphicEditor.h"
#include "UI.h"
#include <iostream>
using namespace std;

GraphicEditor::GraphicEditor() {
    pStart = NULL;
    node_size = 0;
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
            if (pStart == NULL) {
                cout << "List Empty\n";
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
    switch (n) {
    case 1: {
        if (node_size == 0) {
            pStart = new Line();
            pLast = pStart;
        }
        else {
            pLast = pLast->add(new Line());
        }
        node_size++;
        break;
    }
    case 2: {
        if (node_size == 0) {
            pStart = new Circle();
            pLast = pStart;
        }
        else {
            pLast = pLast->add(new Circle());
        }
        node_size++;
        break;
    }
    case 3: {
        if (node_size == 0) {
            pStart = new Rect();
            pLast = pStart;
        }
        else {
            pLast = pLast->add(new Rect());
        }
        node_size++;
        break;
    }
    default:
        cout << "메뉴를 잘못 선택하셨습니다.\n";
    }
}

bool GraphicEditor::del(int n) {
    int k = 0;
    Shape* target_node = pStart;
    Shape* priv_node = nullptr;
    if (n == 0) {
        pStart = pStart->getNext();
        delete target_node;
    }
    else {
        while ((target_node != NULL) && (k < n)) {
            priv_node = target_node;
            target_node = target_node->getNext();
            k++;
        }
        if (target_node == NULL) {
            cout << "없는 노드입니다.\n";
            return false;
        }
        else {
            priv_node->setNext(target_node);
            delete target_node;
        }
    }
    node_size--;
    return true;
}

void GraphicEditor::show() {
    Shape* p = pStart;
    int i = 0;
    if (p == NULL) {
        cout << "남은 도형이 없습니다 !!!\n";
    }
    else {
        while (p != NULL) {
            cout << i << ": ";
            p->paint();
            p = p->getNext();
            i++;
        }
    }
}
