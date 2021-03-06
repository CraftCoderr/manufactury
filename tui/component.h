#ifndef MANUFACTURY_COMPONENT_H
#define MANUFACTURY_COMPONENT_H

#include <panel.h>
#include <key_codes.h>

typedef struct Component Component;

struct Component {
    void* spec;
    void* custom;
    char* id; //debug???
    bool visibility;
    bool visible;
    bool tabFocusing;
    Component* prevFocus;
    Component* nextFocus;
    void (* Show)(Component* component);
    void (* Hide)(Component* component);
    void (* OnKeyClick)(Component* handle, int key, unsigned long modifiers);
    //возвращает true, если focus получен успешно, иначе false и необходимо перевести фокус на следующий элемент
    bool (* OnFocusGet)(Component* handle);
    //возвращает true, если происходит перефокусировка внутри компонента, иначе false и фокус переходит на следующий Component
    bool (* OnFocusChange)(Component* handle);
    void (* OnFocusLost)(Component* handle);
};

Component* CreateComponent();

void ShowComponent(Component* component);

void HideComponent(Component* component);

void FocusSingleComponent(Component* component);

void FocusPrevComponent(Component* resetComponent);

void FocusNextComponent(Component* resetComponent);

void DefocusComponent(Component* component);

Component* GetFocusedComponent(void);

void ComponentSetVisibility(Component* component, bool visibility);

void ComponentHandleMouseEvent(MEVENT event);

void ComponentHandleKeyboardEvent(int key, unsigned long modifiers);

//debug???
int GetNextId();

#endif //MANUFACTURY_COMPONENT_H
