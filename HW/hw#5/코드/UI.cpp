#include "UI.h"
#include <iostream>
using namespace std;

int UI::show_menu() {
    int num;
    cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
    cin >> num;
    return num;
}

int UI::input_shape() {
    int num;
    cout << "��:1, ��:2, �簢��:3 >> ";
    cin >> num;
    return num;
}

int UI::del_index() {
    int num;
    cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
    cin >> num;
    return num;
}
