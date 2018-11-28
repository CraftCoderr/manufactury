#ifndef MANUFACTURY_EDIT_H
#define MANUFACTURY_EDIT_H

#include <view/component.h>
#include <view/interactive_panel.h>

typedef struct Edit Edit;
typedef struct EditStyle EditStyle;

struct Edit {
    EditStyle* style;
    bool enabled;
    int size;
    int pos;
    int selected;
    int length;
    wchar_t* value;
    void (* OnValueEnter)(Component* handle);
    InteractivePanel* panel;
};

struct EditStyle {
    int defaultColor;
    int disabledColor;
    int activeColor;
};

Component* CreateEdit(EditStyle* style, int x, int y, int size);

void EditSetEnabled(Component* handle, bool enabled);

void EditSetValue(Component* handle, wchar_t* value);

void EditSetEnterAction(Component* handle, void (* OnValueEnter)(Component* handle));

EditStyle* CreateEditStyle(int defaultColor, int disabledColor, int activeColor);

#endif //MANUFACTURY_EDIT_H
