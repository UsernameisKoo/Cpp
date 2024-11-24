#include "UI.h"
#include <iostream>
using namespace std;

int UI::show_menu() {
    int num;
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
    cin >> num;
    return num;
}

int UI::input_shape() {
    int num;
    cout << "선:1, 원:2, 사각형:3 >> ";
    cin >> num;
    return num;
}

int UI::del_index() {
    int num;
    cout << "삭제하고자 하는 도형의 인덱스 >> ";
    cin >> num;
    return num;
}
