#include <stdio.h>
#include <curses.h>
#include <panel.h>
#include <src/log.h>
#include <tui/styles.h>
#include <tui/dialog.h>
#include <edit/edit_view.h>
#include <model/data_source.h>
#include <edit/id_input_dialog.h>
#include <report/report_view.h>
#include <report/report_param_dialog.h>
#include <main/filter_dialog.h>
#include "global.h"
#include "main/main_view.h"
#include "main/main_presenter.h"
#include "version.h"

#ifdef DEBUG_LOG
    #define LOG_FILE "log.txt"
#endif

void initPDCurses() {
    //инициализация главного окна
    initscr();
    //режим распознавания каждого нажатия клавиши без ожадания Enter
    cbreak();
    //отключение отображения введенного символа
    noecho();
    //отключение курсора
    curs_set(0);
    //неблокирующий ввод
    nodelay(stdscr, TRUE);
    //распознавание функциональных кнопок клавиатуры(F1, ...)
    keypad(stdscr, TRUE);
    //сохранение модификаторов нажатых клавиш при чтении(Ctrl, Alt, Shift, ...)
    PDC_save_key_modifiers(TRUE);
    //поддержка цвета
    start_color();
    //поддержка мыши
    mouse_set(ALL_MOUSE_EVENTS);
    //установка заголовка окна программы
    PDC_set_title("Manufactury v" MANUFACTURY_VERSION);
}

void endCurses() {
    //завершение работы curses
    endwin();
}

int main(int argc, char** argv) {
#ifdef DEBUG_LOG
    FILE* log = fopen(LOG_FILE, "wt");
    log_set_fp(log);
#endif
    initPDCurses();
    InitStyle();
    InitHotKeyHandler(NULL);
    InitDataSource();
    InitMainView();
    InitDialogsLayouts(dialogBackground);
    InitDataDialog(dialogBackground);
    InitIdInputDialog(dialogBackground);
    InitReportParamDialog(dialogBackground);
    InitFilterDialog(dialogBackground);
    InitReportView(dialogBackground);
    InitApplication(NULL);
    StartControl();
    endCurses();
#ifdef DEBUG_LOG
    fclose(log);
#endif
}