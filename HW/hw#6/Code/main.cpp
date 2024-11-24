#include "GraphicEditor.h"

int main() {
    GraphicEditor* g_editor = new GraphicEditor;
    g_editor->run();
    delete g_editor;

    return 0;
}