#include "Controller.h"
#include "General.h"

void Controller::addEmployee() {
    addEmployeeView->showAddingEmployee();
    size_t Id = addEmployeeView->getNewEmployeeId();
    std::string name = addEmployeeView->getNewEmployeeName();
    int managerId = addEmployeeView->getManagersId();

    if (!employeeList->addEmployee(Id, name, managerId))
        addEmployeeView->showError();
    else
        addEmployeeView->showEmployeeAdded();
}

void Controller::changeManager() {
    changeManagerMenuView->showChangingEmployee();
    size_t Id = changeManagerMenuView->getId();
    int managerId = changeManagerMenuView->getNewManagersId();

    if (!employeeList->setManager(Id, managerId))
        changeManagerMenuView->showError();
    else
        changeManagerMenuView->showManagerChanged();
}

void Controller::showEmployees() {
    employeesView->showEmployees(employeeList);
}

void Controller::employeesMenu() {
    std::string command;
    while (command != "e") {
        employeesView->showEmployeesMenu();
        command = employeesView->getEmployeeMenuCommand();
        if (command == "1")
            addEmployee();
        else if (command == "2")
            changeManager();
        else if (command == "3")
            showEmployees();
        else if (command == "e")
            return;
    }
}

void Controller::addTask() {
    size_t taskId;
    std::string name;
    std::string description;
    size_t employeeId;

    addTaskView->showAddingNewTask();

    if (userId == -1) {
        addTaskView->showGuestAddingTaskError();

        return;
    }

    taskId = addTaskView->getTaskId();
    name = addTaskView->getTaskName();
    description = addTaskView->getTaskDescription();
    employeeId = addTaskView->getAssigneeId();

    if (!taskList->addTask(taskId, name, description, employeeId, userId))
        addTaskView->showError();
    else
        addTaskView->showTaskAdded();
}

void Controller::changeTask() {
    size_t taskId;

    changeTaskView->showChangingTask();

    if (userId == -1) {
        changeTaskView->showGuestChangingTaskError();

        return;
    }

    taskId = changeTaskView->getTaskId();

    Task *task = taskList->getTask(taskId);

    if (task == nullptr) {
        changeTaskView->showWrongIdError();
    } else {
        std::string command;
        changeTaskView->showTaskChangingMenu();
        command = changeTaskView->getTaskChangingCommand();
        if (command == "1") {
            int employeeId = changeTaskView->getEmployeeId();

            Employee *employee = employeeList->getEmployee(employeeId);
            if (employee == nullptr && employeeId >= 0) {
                changeTaskView->showIncorrectEmployeeId();
            } else {
                task->assignEmployee(employeeId, userId);
                changeTaskView->showChangedAssignedEmployee();
            }
        } else if (command == "2") {
            changeTaskView->showStatusMenu();
            int status = changeTaskView->getStatusMenuCommand();
            if (status < 1 || status > 3)
                changeTaskView->showIncorrectStatus();
            else {
                task->changeStatus(status, userId);
                changeTaskView->showStatusChanged();

                if (status == 3 && task->getEmployeeId() >= 0) {
                    Employee *employee = employeeList->getEmployee(task->getEmployeeId());
                    employee->getDailyReport()->addTask(taskId);
                    employee->getSprintDraft()->addTask(taskId);
                    changeTaskView->showResolvedTaskAdded();
                }
            }
        } else if (command == "3") {
            std::string comment = changeTaskView->getComment();
            task->addComment(comment, userId);
            changeTaskView->showCommentAdded();
        } else {
            changeTaskView->showWrongOption();
        }
    }
}

void Controller::showTask() {
    taskView->showPrintingTaskDetails();

    size_t taskId = taskView->getTaskId();

    Task *task = taskList->getTask(taskId);

    if (task == nullptr) {
        taskView->showWrongId();

        return;
    }

    taskView->showTask(task);
    taskView->showMenu();
    std::string command = taskView->getMenuCommand();

    if (command == "1") {
        taskView->showComments(task->getComments());
    } else if (command == "2") {
        taskView->showHistory(task->getHistory());
    }
}

void Controller::showFilteredTask() {
    filteringTaskView->showPrintingTasks();
    filteringTaskView->showMenu();
    std::string command = filteringTaskView->getMenuCommand();

    if (command == "1") {
        filteringTaskView->showTaskListById(taskList->getSortedById());
    } else if (command == "2") {
        filteringTaskView->showTaskListByCreationTime(taskList->getSortedByCreationTime());
    } else if (command == "3") {
        filteringTaskView->showTaskListByChangeTime(taskList->getSortedByLastChangeTime());
    } else if (command == "4" || command == "5" || command == "6") {
        size_t employeeId = filteringTaskView->getEmployeeId();
        Employee *employee = employeeList->getEmployee(employeeId);
        if (employee == nullptr) {
            filteringTaskView->showEmployeeIdError();
        } else if (command == "4") {
            filteringTaskView->showTaskList(taskList->getAssigned(employeeId));
        } else if (command == "5") {
            filteringTaskView->showTaskList(taskList->getEdited(employeeId));
        } else if (command == "6") {
            filteringTaskView->showTaskList(taskList->getSubordinated(employee->getAllSubordinatesId()));
        }
    } else {
        filteringTaskView->showIncorrectOption();
    }
}

void Controller::taskMenu() {
    std::string command;
    while (command != "e") {
        taskMenuView->showTaskMenu();
        command = taskMenuView->getTaskCommand();
        if (command == "1")
            addTask();
        else if (command == "2")
            changeTask();
        else if (command == "3")
            showTask();
        else if (command == "4")
            showFilteredTask();
        else if (command == "e")
            return;
    }
}


void Controller::dailyReport() {
    Employee *employee = employeeList->getEmployee(userId);
    Report *report = employee->getDailyReport();

    dailyReportView->showMenu();
    std::string command = dailyReportView->getMenuCommand();

    if (command == "1") {
        report->addText(dailyReportView->getText());
    } else if (command == "2") {
        dailyReportView->showReportInfo(report);
    } else if (command == "3") {
        reportList->addDailyReport(report);
        employee->startNewDailyReport();
    }
}

void Controller::sprintDraft() {
    Employee *employee = employeeList->getEmployee(userId);
    SprintDraft *report = employee->getSprintDraft();

    sprintDraftView->showMenu();
    std::string command = sprintDraftView->getMenuCommand();

    if (command == "1") {
        report->addText(sprintDraftView->getText());
    } else if (command == "2") {
        sprintDraftView->showReportInfo(report);
    } else if (command == "3") {
        const std::vector<SprintDraft *> &subordinateReports = report->getSubordinateReports();
        for (size_t i = subordinateReports.size(); i > 0; --i) {
            SprintDraft *subordinatesReport = subordinateReports[i - 1];
            sprintDraftView->showSubordinatesReport(subordinatesReport);
            sprintDraftView->showSubordinatesMenu();

            command = sprintDraftView->getSubordinatesCommand();
            if (command == "1") {
                sprintDraftView->showReportText(subordinatesReport);

            } else if (command == "2") {
                continue;
            } else if (command == "3") {
                return;
            }
        }
    } else if (command == "4") {
        employeeList->getTeamlead().getSprintReport()->addSubordinateReport(report);
        Employee *manager = employee->getManager();
        if (manager != nullptr)
            manager->getSprintDraft()->addSubordinateReport(report);
        employee->startNewSprintDraft();
    }
}

void Controller::submittedReports() {
    std::string command;

    submittedReportsView->showMenu();
    command = submittedReportsView->getMenuCommand();

    if (command == "1") {
        const std::vector<Report *> &reports = reportList->getDailyReports();
        for (size_t i = reports.size(); i > 0; --i) {
            Report *report = reports[i - 1];
            submittedReportsView->showReportInfo(report);
            submittedReportsView->showReportMenu();
            command = submittedReportsView->getReportMenuCommand();
            if (command == "1") {
                submittedReportsView->showReportText(report);

            } else if (command == "2") {
                continue;
            } else if (command == "3") {
                return;
            }
        }
    }
    if (command == "2") {
        const std::vector<SprintDraft *> &reports = reportList->getSprintReports();
        for (size_t i = reports.size(); i > 0; --i) {
            SprintDraft *sprintReport = reports[i - 1];
            submittedReportsView->showSprintReport(sprintReport);
            submittedReportsView->showSpringReportMenu();
            command = submittedReportsView->getSprintReportMenuCommand();

            if (command == "1") {
                submittedReportsView->showSprintReportText(sprintReport);
            } else if (command == "2") {
                continue;
            } else if (command == "3") {
                return;
            }
        }
    }
}

void Controller::sprintReport() {
    TeamleadWrapper &teamlead = employeeList->getTeamlead();

    if (userId != teamlead.getEmployee()->getId()) {
        sprintReportView->showTeamleadError();

        return;
    }

    SprintReport *report = teamlead.getSprintReport();

    sprintReportView->showMenu();
    std::string command = sprintReportView->getMenuCommand();

    if (command == "1") {
        report->addText(sprintReportView->getText());
    } else if (command == "2") {
        sprintReportView->showReportInfo(report);
    } else if (command == "3") {
        const std::vector<SprintDraft *> &subordinateReports = report->getSubordinateReports();
        for (size_t i = subordinateReports.size(); i > 0; --i) {
            SprintDraft *subordinatesReport = subordinateReports[i - 1];
            sprintReportView->showSubordinatesReport(subordinatesReport);
            sprintReportView->showSubordinatesMenu();

            command = sprintReportView->getSubordinatesCommand();
            if (command == "1") {
                sprintReportView->showReportText(subordinatesReport);
            } else if (command == "2") {
                continue;
            } else if (command == "3") {
                return;
            }
        }
    } else if (command == "4") {
        reportList->addSprintReport(report);
        teamlead.startNewSprintReport();
    }
}

void Controller::reportMenu() {
    if (userId == -1) {
        reportMenuView->showGuestsError();

        return;
    }

    std::string command;
    while (command != "e") {
        reportMenuView->showMenu();
        command = reportMenuView->getMenuCommand();
        if (command == "1")
            dailyReport();
        else if (command == "2")
            sprintDraft();
        else if (command == "3")
            submittedReports();
        else if (command == "4")
            sprintReport();
        else if (command == "e")
            return;
    }
}


void Controller::changeUser() {
    int newId = changeUserView->getUserId();
    if (newId < 0) {
        newId = -1;
    } else if (employeeList->getEmployee(newId) == nullptr) {
        changeUserView->showNoSuchError();

        return;
    }

    userId = newId;
}

Controller::Controller(EmployeeList *_employeeList, TaskList *_taskList, ReportList *_reportList) :
        employeeList(_employeeList), taskList(_taskList), reportList(_reportList) {
    this->addEmployeeView = new AddEmployeeView();
    this->addTaskView = new AddTaskView();
    this->changeManagerMenuView = new ChangeManagerMenuView();
    this->employeesView = new EmployeesView();
    this->changeTaskView = new ChangeTaskView();
    this->taskView = new TaskView();
    this->filteringTaskView = new FilteringTasksView();
    this->taskMenuView = new TaskMenuView();
    this->dailyReportView = new DailyReportView();
    this->sprintDraftView = new SprintDraftView();
    this->submittedReportsView = new SubmittedReportsView();
    this->sprintReportView = new SprintReportView();
    this->reportMenuView = new ReportMenuView();
    this->changeUserView = new ChangeUserView();
    this->mainMenuView = new MainMenuView();
}

void Controller::mainMenu() {
    std::string command;
    while (command != "e") {
        mainMenuView->showCurrentUser(userId);
        mainMenuView->showMenu();
        command = mainMenuView->getMenuCommand();
        if (command == "1")
            employeesMenu();
        else if (command == "2")
            taskMenu();
        else if (command == "3")
            reportMenu();
        else if (command == "4")
            changeUser();
        else if (command == "e")
            return;
    }
}
