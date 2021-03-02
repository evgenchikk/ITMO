#pragma once

#include "views/AddEmployeeView.h"
#include "views/ChangeManagerMenuView.h"
#include "views/EmployeesView.h"
#include "views/AddTaskView.h"
#include "views/ChangeTaskView.h"
#include "views/TaskView.h"
#include "views/FilteringTasksView.h"
#include "views/TaskMenuView.h"
#include "views/DailyReportView.h"
#include "views/SprintDraftView.h"
#include "views/SubmittedReportsView.h"
#include "views/SprintReportView.h"
#include "views/ReportMenuView.h"
#include "views/ChangeUserView.h"
#include "views/MainMenuView.h"
#include "EmployeeList.h"
#include "TaskList.h"
#include "ReportList.h"


class Controller {
    int userId = -1;
    EmployeeList *employeeList;
    TaskList *taskList;
    ReportList *reportList;

    AddEmployeeView *addEmployeeView;
    AddTaskView *addTaskView;
    ChangeManagerMenuView *changeManagerMenuView;
    EmployeesView *employeesView;
    ChangeTaskView *changeTaskView;
    TaskView *taskView;
    FilteringTasksView *filteringTaskView;
    TaskMenuView *taskMenuView;
    DailyReportView *dailyReportView;
    SprintDraftView *sprintDraftView;
    SubmittedReportsView *submittedReportsView;
    SprintReportView *sprintReportView;
    ReportMenuView *reportMenuView;
    ChangeUserView *changeUserView;
    MainMenuView *mainMenuView;

    void addEmployee();

    void changeManager();

    void showEmployees();

    void employeesMenu();


    void addTask();

    void changeTask();

    void showTask();

    void showFilteredTask();

    void taskMenu();

    void dailyReport();

    void sprintDraft();

    void submittedReports();

    void sprintReport();

    void reportMenu();


    void changeUser();

public:
    Controller(EmployeeList *_employeeList, TaskList *_taskList, ReportList *_reportList);

    void mainMenu();
};
