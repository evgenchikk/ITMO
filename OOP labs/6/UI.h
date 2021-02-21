#pragma once

#include "EmployeeList.h"
#include "TaskList.h"
#include "ReportList.h"


class UI {
    static const size_t PRINT_SIZE = 5;

    int userID = -1;
    EmployeeList *employeeList;
    TaskList *taskList;
    ReportList *reportList;

    void addEmployee();

    void changeManager();

    void printEmployees();

    void employeesMenu();


    void addTask();

    void changeTask();

    void printTask();

    void printFilteredTask();

    void taskMenu();

    void dailyReport();

    void sprintReport();

    void submittedReports();

    void reportMenu();


    void changeUser();

public:
    UI(EmployeeList *_employeeList, TaskList *_taskList, ReportList *_reportList);

    void mainMenu();
};
