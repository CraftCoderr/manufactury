#include <src/log.h>
#include "label.h"

void LabelShow(Component* handle) {
    Label* label = handle->spec;
    PanelShow(label->panelLabel);
}

void LabelHide(Component* handle) {
    Label* label = handle->spec;
    PanelHide(label->panelLabel);
}

bool LabelOnFocusGet(Component* component) {
    return false;
}

Component* CreateLabel(int x, int y, int size, wchar_t* text) {
    Component* handle = CreateComponent();
    InteractivePanel* panelLabel = CreateInteractivePanel(handle, x, y, size, 1);
    Label* label = malloc(sizeof(Label));
    label->size = size;
    label->text = malloc(sizeof(wchar_t) * (size + 1));
    wmemcpy_s(label->text, (size_t) size, text, (size_t) size); //wcscpy_s не работает
    label->panelLabel = panelLabel;
    wmove(panelLabel->window, 0, 0);
    waddwstr(panelLabel->window, label->text);

    handle->spec = label;

    handle->id = malloc(sizeof(char) * 10);
    handle->id[10] = '\0';
    sprintf(handle->id, "%s %d", "Label", GetNextId());

    handle->Show = LabelShow;
    handle->Hide = LabelHide;
    handle->OnFocusGet = LabelOnFocusGet;
    return handle;
}

void LabelSetText(Component* handle, wchar_t* text) {
    Label* label = handle->spec;
    wmemcpy_s(label->text, (size_t) label->size, text, (size_t) label->size);
    wmove(label->panelLabel->window, 0, 0);
    waddwstr(label->panelLabel->window, label->text);
}