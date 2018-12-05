#include <view/component/label.h>
#include <src/log.h>
#include <model/filter.h>
#include "data_dialog.h"
#include "styles.h"

#define DIALOG_WIDTH 38
#define DIALOG_HEIGHT 16

#define ID_INPUT_Y 1
#define SURNAME_INPUT_Y 2
#define NAME_INPUT_Y 3
#define PATRONYMIC_INPUT_Y 4
#define YOB_INPUT_Y 5
#define GENDER_INPUT_Y 6
#define PROF_INPUT_Y 7
#define EXP_INPUT_Y 8
#define CLASS_INPUT_Y 9
#define DEPT_INPUT_Y 10
#define PLOT_INPUT_Y 11
#define SALARY_INPUT_Y 12

#define ID_INPUT_WIDTH 5
#define SURNAME_INPUT_WIDTH 16
#define NAME_INPUT_WIDTH 16
#define PATRONYMIC_INPUT_WIDTH 16
#define YOB_INPUT_WIDTH 4
#define GENDER_INPUT_WIDTH 2
#define PROF_INPUT_WIDTH 16
#define EXP_INPUT_WIDTH 2
#define CLASS_INPUT_WIDTH 2
#define DEPT_INPUT_WIDTH 2
#define PLOT_INPUT_WIDTH 2
#define SALARY_INPUT_WIDTH 7

#define ID_LABEL_WIDTH 15
#define SURNAME_LABEL_WIDTH 7
#define NAME_LABEL_WIDTH 3
#define PATRONYMIC_LABEL_WIDTH 8
#define YOB_LABEL_WIDTH 12
#define GENDER_LABEL_WIDTH 3
#define PROF_LABEL_WIDTH 9
#define EXP_LABEL_WIDTH 11
#define CLASS_LABEL_WIDTH 6
#define DEPT_LABEL_WIDTH 3
#define PLOT_LABEL_WIDTH 7
#define SALARY_LABEL_WIDTH 8

#define MAX_WIDTH 16

#define INPUT_X MAX_WIDTH + 2

#define X

Layout* dialog;

Component* idEdit;
Component* surnameEdit;
Component* nameEdit;
Component* patronymicEdit;
Component* yobEdit;
Component* genderSelect;
Component* profEdit;
Component* expEdit;
Component* classSelect;
Component* deptEdit;
Component* plotEdit;
Component* salaryEdit;

Component* idLabel;
Component* surnameLabel;
Component* nameLabel;
Component* patronymicLabel;
Component* yobLabel;
Component* genderLabel;
Component* profLabel;
Component* expLabel;
Component* classLabel;
Component* deptLabel;
Component* plotLabel;
Component* salaryLabel;

Component* confirmButton;
Component* cancelButton;

Component* messageLabel;

int labeloffset(int x, int width) {
    return x + 1 + (MAX_WIDTH - width);
}

void (* confirmAction)(void);
void (* cancelAction)(void);

void OnConfirm(Component* handle) {
    ActivateLayout(NULL);
    if (confirmAction != NULL) confirmAction();
}

void OnCancel(Component* handle) {
    ActivateLayout(NULL);
    if (cancelAction != NULL) cancelAction();
}

void InitDataDialog(int color) {
    int x = (COLS - DIALOG_WIDTH) / 2;
    int y = (LINES - DIALOG_HEIGHT) / 2;

    dialog = CreateLayout(x, y, DIALOG_WIDTH, DIALOG_HEIGHT);
    wbkgd(dialog->window, COLOR_PAIR(color));

    idLabel = CreateLabel(addLabelStyle, labeloffset(x, ID_LABEL_WIDTH), y + ID_INPUT_Y, ID_LABEL_WIDTH, L"Табельный номер");
    idEdit = CreateEdit(addEditStyle, x + INPUT_X, y + ID_INPUT_Y, ID_INPUT_WIDTH);
    EditSetFilter(idEdit, PositiveNumberFilter);
    LayoutAddComponent(dialog, idLabel);
    LayoutAddComponent(dialog, idEdit);

    surnameLabel = CreateLabel(addLabelStyle, labeloffset(x, SURNAME_LABEL_WIDTH), y + SURNAME_INPUT_Y, SURNAME_LABEL_WIDTH, L"Фамилия");
    surnameEdit = CreateEdit(addEditStyle, x + INPUT_X, y + SURNAME_INPUT_Y, SURNAME_INPUT_WIDTH);
    LayoutAddComponent(dialog, surnameLabel);
    LayoutAddComponent(dialog, surnameEdit);

    nameLabel = CreateLabel(addLabelStyle, labeloffset(x, NAME_LABEL_WIDTH), y + NAME_INPUT_Y, NAME_LABEL_WIDTH, L"Имя");
    nameEdit = CreateEdit(addEditStyle, x + INPUT_X, y + NAME_INPUT_Y, NAME_INPUT_WIDTH);
    LayoutAddComponent(dialog, nameLabel);
    LayoutAddComponent(dialog, nameEdit);

    patronymicLabel = CreateLabel(addLabelStyle, labeloffset(x, PATRONYMIC_LABEL_WIDTH), y + PATRONYMIC_INPUT_Y, PATRONYMIC_LABEL_WIDTH, L"Отчество");
    patronymicEdit = CreateEdit(addEditStyle, x + INPUT_X, y + PATRONYMIC_INPUT_Y, PATRONYMIC_INPUT_WIDTH);
    LayoutAddComponent(dialog, patronymicLabel);
    LayoutAddComponent(dialog, patronymicEdit);

    yobLabel = CreateLabel(addLabelStyle, labeloffset(x, YOB_LABEL_WIDTH), y + YOB_INPUT_Y, YOB_LABEL_WIDTH, L"Год рождения");
    yobEdit = CreateEdit(addEditStyle, x + INPUT_X, y + YOB_INPUT_Y, YOB_INPUT_WIDTH);
    EditSetFilter(yobEdit, PositiveNumberFilter);
    LayoutAddComponent(dialog, yobLabel);
    LayoutAddComponent(dialog, yobEdit);

    genderLabel = CreateLabel(addLabelStyle, labeloffset(x, GENDER_LABEL_WIDTH), y + GENDER_INPUT_Y, GENDER_LABEL_WIDTH, L"Пол");
    genderSelect = CreateSelect(addSelectStyle, x + INPUT_X, y + GENDER_INPUT_Y, GENDER_INPUT_WIDTH, 2, L"М", L"Ж");
    LayoutAddComponent(dialog, genderLabel);
    LayoutAddComponent(dialog, genderSelect);

    profLabel = CreateLabel(addLabelStyle, labeloffset(x, PROF_LABEL_WIDTH), y + PROF_INPUT_Y, PROF_LABEL_WIDTH, L"Профессия");
    profEdit = CreateEdit(addEditStyle, x + INPUT_X, y + PROF_INPUT_Y, PROF_INPUT_WIDTH);
    LayoutAddComponent(dialog, profLabel);
    LayoutAddComponent(dialog, profEdit);

    expLabel = CreateLabel(addLabelStyle, labeloffset(x, EXP_LABEL_WIDTH), y + EXP_INPUT_Y, EXP_LABEL_WIDTH, L"Опыт работы");
    expEdit = CreateEdit(addEditStyle, x + INPUT_X, y + EXP_INPUT_Y, EXP_INPUT_WIDTH);
    EditSetFilter(expEdit, PositiveNumberFilter);
    LayoutAddComponent(dialog, expLabel);
    LayoutAddComponent(dialog, expEdit);

    classLabel = CreateLabel(addLabelStyle, labeloffset(x, CLASS_LABEL_WIDTH), y + CLASS_INPUT_Y, CLASS_LABEL_WIDTH, L"Разряд");
    classSelect = CreateSelect(addSelectStyle, x + INPUT_X, y + CLASS_INPUT_Y, CLASS_INPUT_WIDTH, 3, L"1", L"2", L"3");
    LayoutAddComponent(dialog, classLabel);
    LayoutAddComponent(dialog, classSelect);

    deptLabel = CreateLabel(addLabelStyle, labeloffset(x, DEPT_LABEL_WIDTH), y + DEPT_INPUT_Y, DEPT_LABEL_WIDTH, L"Цех");
    deptEdit = CreateEdit(addEditStyle, x + INPUT_X, y + DEPT_INPUT_Y, DEPT_INPUT_WIDTH);
    EditSetFilter(deptEdit, PositiveNumberFilter);
    LayoutAddComponent(dialog, deptLabel);
    LayoutAddComponent(dialog, deptEdit);

    plotLabel = CreateLabel(addLabelStyle, labeloffset(x, PLOT_LABEL_WIDTH), y + PLOT_INPUT_Y, PLOT_LABEL_WIDTH, L"Участок");
    plotEdit = CreateEdit(addEditStyle, x + INPUT_X, y + PLOT_INPUT_Y, PLOT_INPUT_WIDTH);
    EditSetFilter(plotEdit, PositiveNumberFilter);
    LayoutAddComponent(dialog, plotLabel);
    LayoutAddComponent(dialog, plotEdit);

    salaryLabel = CreateLabel(addLabelStyle, labeloffset(x, SALARY_LABEL_WIDTH), y + SALARY_INPUT_Y, SALARY_LABEL_WIDTH, L"Зарплата");
    salaryEdit = CreateEdit(addEditStyle, x + INPUT_X, y + SALARY_INPUT_Y, SALARY_INPUT_WIDTH);
    EditSetFilter(salaryEdit, PositiveNumberFilter);
    LayoutAddComponent(dialog, salaryLabel);
    LayoutAddComponent(dialog, salaryEdit);

    confirmButton = CreateButton(addButtonStyle, x + 5, y + (DIALOG_HEIGHT - 2), 8, L"   Ок   ", OnConfirm);
    cancelButton = CreateButton(addButtonStyle, x + 23, y + (DIALOG_HEIGHT - 2), 8, L" Отмена ", OnCancel);
    LayoutAddComponent(dialog, confirmButton);
    LayoutAddComponent(dialog, cancelButton);
}

void ShowAddDialog(void (* onConfirm)(void), void (* onCancel)(void)) {
    EditSetValue(idEdit, L"");
    EditSetValue(surnameEdit, L"");
    EditSetValue(nameEdit, L"");
    EditSetValue(patronymicEdit, L"");
    EditSetValue(yobEdit, L"");
    SelectSetValue(genderSelect, 0);
    EditSetValue(profEdit, L"");
    EditSetValue(expEdit, L"");
    SelectSetValue(classSelect, 0);
    EditSetValue(deptEdit, L"");
    EditSetValue(plotEdit, L"");
    EditSetValue(salaryEdit, L"");
    confirmAction = onConfirm;
    cancelAction = onCancel;
    ActivateLayout(dialog);
}

void ShowEditDialog(Employee* e, void (* onConfirm)(void), void (* onCancel)(void)) {
    wchar_t id[ID_INPUT_WIDTH];
    swprintf(id, ID_INPUT_WIDTH, L"%d", e->id);
    EditSetValue(idEdit, id);
    EditSetValue(surnameEdit, e->surname);
    EditSetValue(nameEdit, e->name);
    EditSetValue(patronymicEdit, e->patronymic);
    wchar_t yob[YOB_INPUT_WIDTH];
    swprintf(yob, YOB_INPUT_WIDTH, L"%d", e->yearOfBirth);
    EditSetValue(yobEdit, yob);
    SelectSetValue(genderSelect, e->gender ? 0 : 1);
    EditSetValue(profEdit, e->profession);
    wchar_t exp[EXP_INPUT_WIDTH];
    swprintf(exp, EXP_INPUT_WIDTH, L"%d", e->experience);
    EditSetValue(expEdit, exp);
    SelectSetValue(classSelect, 0);
    wchar_t dept[DEPT_INPUT_WIDTH];
    swprintf(dept, DEPT_INPUT_WIDTH, L"%d", e->departmentId);
    EditSetValue(deptEdit, dept);
    wchar_t plot[PLOT_INPUT_WIDTH];
    swprintf(plot, PLOT_INPUT_WIDTH, L"%d", e->plotId);
    EditSetValue(plotEdit, plot);
    wchar_t salary[SALARY_INPUT_WIDTH];
    swprintf(salary, SALARY_INPUT_WIDTH, L"%d", e->salary);
    EditSetValue(salaryEdit, salary);
}

Employee* GetEnteredData() {
    Employee* e = malloc(sizeof(Employee));
    int id = parseInt(EditGetValue(idEdit));
//    if (id <= 0 || id > INT_MAX) return NULL; //show error message, free(e)
    e->id = id;

    EmployeeSetSurname(e, EditGetValue(surnameEdit));

    EmployeeSetName(e, EditGetValue(nameEdit));

    EmployeeSetPatronymic(e, EditGetValue(patronymicEdit));

    int yob = parseInt(EditGetValue(yobEdit));
//    if (yob <= 0 || yob > INT16_MAX) return;
    e->yearOfBirth = (short) yob;

    e->gender = ValueOfGender(SelectGetValue(genderSelect));

    EmployeeSetProfession(e, EditGetValue(profEdit));

    int exp = parseInt(EditGetValue(expEdit));
//    if (exp < 0 || exp > CHAR_MAX) return;
    e->experience = (char) exp;

    e->class = ValueOfProfClass(SelectGetValue(classSelect));

    int dept = parseInt(EditGetValue(deptEdit));
//    if (dept <= 0 || dept > CHAR_MAX) return;
    e->departmentId = (char) dept;

    int plot = parseInt(EditGetValue(plotEdit));
//    if (plot <= 0 || plot > CHAR_MAX) return;
    e->plotId = (char) plot;

    int salary = parseInt(EditGetValue(salaryEdit));
//    if (salary <= 0 || salary > INT_MAX) return;
    e->salary = salary;
    return e;
}