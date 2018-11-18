#include <malloc.h>
#include <src/log.h>
#include "interactive_panel.h"

void DefaultOnMouseClick(InteractivePanel* handle, MEVENT event) {
    //noop
}

InteractivePanel* CreateInteractivePanel(Component* holder, int x, int y, int width, int height) {
    WINDOW* window = newwin(height, width, y, x);
    PANEL* panel = new_panel(window);
    InteractivePanel* interactivePanel = malloc(sizeof(InteractivePanel));
    hide_panel(panel);
    set_panel_userptr(panel, interactivePanel);
    interactivePanel->panel = panel;
    interactivePanel->window = window;
    interactivePanel->holder = holder;
    interactivePanel->OnMouseClick = DefaultOnMouseClick;
    return interactivePanel;
}