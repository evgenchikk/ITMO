#include "UI.h"
#include <iostream>
#include <cstdlib>
#include "General.h"


void UI::addEmployee() {
    std::string input;
    size_t ID;
    std::string name;
    int managerID;
    system("clear");
    std::cout << "  Adding new employee\n";

    std::cout << "ID: ";
    getline(std::cin, input);
    ID = stoi(input);

    std::cout << "Name: ";
    getline(std::cin, name);

    std::cout << "Manager's ID (-1 to make new employee the teamlead): ";
    getline(std::cin, input);
    managerID = stoi(input);

    if (!employeeList->addEmployee(ID, name, managerID))
        std::cout << "Error!\n";
    else
        std::cout << "Added new employee!\n";
  
    return;
}


void UI::changeManager() {
    std::string input;
    size_t ID;
    int managerID;
    system("clear");
    std::cout << "  Changing employee's manager\n";

    std::cout << "ID: ";
    getline(std::cin, input);
    ID = stoi(input);

    std::cout << "New manager's ID (-1 to make employee the teamlead): ";
    getline(std::cin, input);
    managerID = stoi(input);

    if (!employeeList->setManager(ID, managerID))
        std::cout << "Error!\n";
    else
        std::cout << "Changed manager!\n";

    return;
}


void UI::printEmployees() {
    system("clear");
    employeeList->print();

    return;
}


void UI::employeesMenu() {
    std::string input;
    while (input != "e") {
        system("clear");
        std::cout << "  Employee Menu\n";
        std::cout << "1 - Add new employee\n";
        std::cout << "2 - Change employee's manager\n";
        std::cout << "3 - Print all employees\n";
        std::cout << "e - Exit\n";
        std::cout << std::endl;
        getline(std::cin, input);
        if (input == "1")
            addEmployee();
        else if (input == "2")
            changeManager();
        else if (input == "3")
            printEmployees();
        else if (input == "e")
            return;
    }
}


void UI::addTask() {
    std::string input;
    size_t taskID;
    std::string name;
    std::string description;
    size_t employeeID;

    system("clear");
    std::cout << "  Adding new task\n";

    if (userID == -1) {
        std::cout << "Guests can't add tasks!\n";
        return;
    }

    std::cout << "Task ID: ";
    getline(std::cin, input);
    taskID = stoi(input);

    std::cout << "Name: ";
    getline(std::cin, name);

    std::cout << "Description: ";
    getline(std::cin, description);

    std::cout << "Employee's ID (-1 to don't assign): ";
    getline(std::cin, input);
    employeeID = stoi(input);

    if (!taskList->addTask(taskID, name, description, employeeID, userID))
        std::cout << "Error!\n";
    else
        std::cout << "Added new task!\n";

    return;
}


void UI::changeTask() {
    std::string input;
    size_t taskID;

    system("clear");
    std::cout << "  Changing task\n";

    if (userID == -1) {
        std::cout << "Guests can't change tasks!\n";

        return;
    }

    std::cout << "Task ID: ";
    getline(std::cin, input);
    taskID = stoi(input);

    Task *task = taskList->getTask(taskID);

    if (task == nullptr) {
        std::cout << "Wrong ID!\n";
    } else {
        std::cout << "1 - Change assigned employee\n";
        std::cout << "2 - Change status\n";
        std::cout << "3 - Add comment\n";
        getline(std::cin, input);
        if (input == "1") {
            int employeeID;
            std::cout << "Employee ID (-1 to unassign task): ";
            getline(std::cin, input);
            employeeID = stoi(input);

            Employee *employee = employeeList->getEmployee(employeeID);
            if (employee == nullptr && employeeID >= 0) {
                std::cout << "Incorrect employee ID!\n";
            } else {
                task->assignEmployee(employeeID, userID);
                std::cout << "Changed assigned employee!\n";
            }
        } else if (input == "2") {
            std::cout << "1 - Open\n";
            std::cout << "2 - Active\n";
            std::cout << "3 - Resolved\n";
            getline(std::cin, input);
            int status = stoi(input);
            if (status < 1 || status > 3)
                std::cout << "Incorrect status!\n";
            else {
                task->changeStatus(status, userID);
                std::cout << "Changed status!\n";

                if (status == 3 && task->getEmployeeID() >= 0) {
                    Employee *employee = employeeList->getEmployee(task->getEmployeeID());
                    employee->getDailyReport()->addTask(taskID);
                    employee->getSprintReport()->addTask(taskID);
                    std::cout << "Added resolved task to report!\n";
                }
            }
        } else if (input == "3") {
            std::cout << "Comment: ";
            getline(std::cin, input);
            task->addComment(input, userID);
            std::cout << "Added comment!\n";
        } else {
            std::cout << "Wrong option!\n";
        }
    }

    return;
}


void UI::printTask() {
    std::string input;
    size_t taskID;
    system("clear");
    std::cout << "  Printing Task Details\n";

    std::cout << "Task ID: ";
    getline(std::cin, input);
    taskID = stoi(input);

    Task *task = taskList->getTask(taskID);

    if (task == nullptr) {
        std::cout << "Wrong ID!\n";

        return;
    }

    std::cout << "Name: " << task->getName() << std::endl;
    std::cout << "Description: " << task->getDescription() << std::endl;
    std::cout << "Assigned Employee's ID: " << task->getEmployeeID() << std::endl;
    std::cout << "Status: " << task->getStatus() << std::endl;

    std::cout << std::endl;
    std::cout << "1 - Print comments\n";
    std::cout << "2 - Print history\n";
    getline(std::cin, input);

    if (input == "1") {
        const std::vector<TimedPost *> &comments = task->getComments();
        for (size_t i = 0; i < comments.size(); ++i) {
            std::cout << getDateString(comments[i]->getTime()) << std::endl;
            std::cout << comments[i]->getText() << std::endl;
            std::cout << "By: " << comments[i]->getAuthorID() << std::endl;
            std::cout << std::endl;

            if (i % PRINT_SIZE == PRINT_SIZE - 1) {
                std::cout << "Show more results? (y/n)" << std::endl;
                std::string ans;
                getline(std::cin, ans);
                if (ans != "y")
                    return;
            }
        }
    } else if (input == "2") {
        const std::vector<TimedPost *> &history = task->getHistory();
        for (size_t i = 0; i < history.size(); ++i) {
            std::cout << getDateString(history[i]->getTime()) << std::endl;
            std::cout << history[i]->getText() << std::endl;
            std::cout << "By: " << history[i]->getAuthorID() << std::endl;
            std::cout << std::endl;

            if (i % PRINT_SIZE == PRINT_SIZE - 1) {
                std::cout << "Show more results? (y/n)" << std::endl;
                std::string ans;
                getline(std::cin, ans);
                if (ans != "y")
                    return;
            }
        }
    }

    return;
}


void UI::printFilteredTask() {
    std::string input;

    system("clear");
    std::cout << "  Printing tasks\n";

    std::cout << "1 - Order by ID\n";
    std::cout << "2 - Order by creation date\n";
    std::cout << "3 - Order by last change date\n";
    std::cout << "4 - All tasks, assigned to specific employee\n";
    std::cout << "5 - All tasks, ever edited by specific employee\n";
    std::cout << "6 - All tasks, that are assigned to subordinates of specific employee\n";

    getline(std::cin, input);

    if (input == "1") {
        taskList->printByID();
    } else if (input == "2") {
        taskList->printByCreationTime();
    } else if (input == "3") {
        taskList->printByLastChangeTime();
    } else if (input == "4" || input == "5" || input == "6") {
        std::string option = input;
        size_t employeeID;
        std::cout << "Employee ID: ";
        getline(std::cin, input);
        employeeID = stoi(input);

        Employee *employee = employeeList->getEmployee(employeeID);
        if (employee == nullptr) {
            std::cout << "Incorrect employee ID!\n";
        } else if (option == "4") {
            taskList->printAssigned(employeeID);
        } else if (option == "5") {
            taskList->printEdited(employeeID);
        } else if (option == "6") {
            taskList->printSubordinated(employee->getAllSubordinatesID());
        }
    } else {
        std::cout << "Incorrect option!\n";
    }

    return;
}


void UI::taskMenu() {
    std::string input;
    while (input != "e") {
        system("clear");
        std::cout << "  Task Menu\n";
        std::cout << "1 - Add new task\n";
        std::cout << "2 - Change task\n";
        std::cout << "3 - Print task by ID\n";
        std::cout << "4 - Print task with filter\n";
        std::cout << "e - Exit\n";
        std::cout << std::endl;
        getline(std::cin, input);
        if (input == "1")
            addTask();
        else if (input == "2")
            changeTask();
        else if (input == "3")
            printTask();
        else if (input == "4")
            printFilteredTask();
        else if (input == "e")
            return;
    }
}


void UI::dailyReport() {
    Employee *employee = employeeList->getEmployee(userID);
    Report *report = employee->getDailyReport();

    std::string input;

    system("clear");
    std::cout << "  Daily Report Menu\n";
    std::cout << "1 - Add text to report\n";
    std::cout << "2 - Show report info\n";
    std::cout << "3 - Close report and submit\n";

    getline(std::cin, input);

    if (input == "1") {
        std::cout << "Text: ";
        getline(std::cin, input);
        report->addText(input);
    } else if (input == "2") {
        std::cout << "Resolved tasks: ";
        for (auto t : report->getTasks())
            std::cout << t << " ";
        std::cout << std::endl;
        std::cout << report->getText() << std::endl;
    } else if (input == "3") {
        reportList->addDailyReport(report);
        employee->startNewDailyReport();
    }

    return;
}


void UI::sprintReport() {
    Employee *employee = employeeList->getEmployee(userID);
    SprintReport *report = employee->getSprintReport();

    std::string input;

    system("clear");
    std::cout << "  Sprint Report Menu\n";
    std::cout << "1 - Add text to report\n";
    std::cout << "2 - Show report info\n";
    std::cout << "3 - Show subordinates reports\n";
    std::cout << "4 - Close report and submit\n";

    getline(std::cin, input);

    if (input == "1") {
        std::cout << "Text: ";
        getline(std::cin, input);
        report->addText(input);
    } else if (input == "2") {
        std::cout << "Resolved tasks: ";
        for (auto t : report->getTasks())
            std::cout << t << " ";
        std::cout << std::endl;
        std::cout << report->getText() << std::endl;
    } else if (input == "3") {
        const std::vector<SprintReport *> &subordinateReports = employee->getSprintReport()->getSubordinateReports();
        for (size_t i = subordinateReports.size(); i > 0; --i) {
            SprintReport *t = subordinateReports[i - 1];
            std::cout << t->getAuthorID() << std::endl;
            std::cout << "Resolved tasks: ";
            for (auto id : t->getTasks())
                std::cout << id << " ";
            std::cout << std::endl;

            std::cout << "1 - view report text\n";
            std::cout << "2 - show next report\n";
            std::cout << "3 - exit\n";

            getline(std::cin, input);
            if (input == "1") {
                std::cout << t->getText() << std::endl;
            } else if (input == "2") {
                continue;
            } else if (input == "3") {
                return;
            }
        }
    } else if (input == "4") {
        reportList->addSprintReport(report);
        Employee *manager = employee->getManager();
        if (manager != nullptr)
            manager->getSprintReport()->addSubordinateReport(report);
        employee->startNewSprintReport();
    }

    return;
}


void UI::submittedReports() {
    std::string input;

    system("clear");
    std::cout << "  Submitted Reports Menu\n";
    std::cout << "1 - Print Daily Reports\n";
    std::cout << "2 - Print Sprint Reports\n";

    getline(std::cin, input);

    if (input == "1") {
        const std::vector<Report *> &reports = reportList->getDailyReports();
        for (size_t i = reports.size(); i > 0; --i) {
            Report *t = reports[i - 1];
            std::cout << t->getAuthorID() << std::endl;
            std::cout << "Resolved tasks: ";
            for (auto id : t->getTasks())
                std::cout << id << " ";
            std::cout << std::endl;

            std::cout << "1 - view report text\n";
            std::cout << "2 - show next report\n";
            std::cout << "3 - exit\n";

            getline(std::cin, input);
            if (input == "1") {
                std::cout << t->getText() << std::endl;
                system("clear");
            } else if (input == "2") {
                continue;
            } else if (input == "3") {
                return;
            }
        }
    }
    if (input == "2") {
        const std::vector<SprintReport *> &reports = reportList->getSprintReports();
        for (size_t i = reports.size(); i > 0; --i) {
            SprintReport *t = reports[i - 1];
            std::cout << t->getAuthorID() << std::endl;
            std::cout << "Resolved tasks: ";
            for (auto id : t->getTasks())
                std::cout << id << " ";
            std::cout << std::endl;

            std::cout << "1 - view report text\n";
            std::cout << "2 - show next report\n";
            std::cout << "3 - exit\n";

            getline(std::cin, input);
            if (input == "1") {
                std::cout << t->getText() << std::endl;
                system("pause");
            } else if (input == "2") {
                continue;
            } else if (input == "3") {
                return;
            }
        }
    }

    return;
}


void UI::reportMenu() {
    if (userID == -1) {
        std::cout << "Guests can't edit reports!\n";
        return;
    }

    std::string input;
    while (input != "e") {
        system("clear");
        std::cout << "  Reports Menu\n";
        std::cout << "1 - Daily Report\n";
        std::cout << "2 - Sprint Report\n";
        std::cout << "3 - Submitted Reports\n";
        std::cout << "e - Exit\n";
        std::cout << std::endl;
        getline(std::cin, input);
        if (input == "1")
            dailyReport();
        else if (input == "2")
            sprintReport();
        else if (input == "3")
            submittedReports();
        else if (input == "e")
            return;
    }
}


void UI::changeUser() {
    std::string input;
    system("clear");
    std::cout << "User ID (-1 for Guest): ";
    getline(std::cin, input);
    int newID = stoi(input);
    if (newID < 0)
        newID = -1;
    else if (employeeList->getEmployee(newID) == nullptr)
        std::cout << "No such user!\n";
    else
        userID = newID;

    return;
}


UI::UI(EmployeeList *_employeeList, TaskList *_taskList, ReportList *_reportList)
  : employeeList(_employeeList), taskList(_taskList), reportList(_reportList)
  {}


void UI::mainMenu() {
    std::string input;
    while (input != "e") {
        system("clear");
        std::cout << "Current User: ";
        if (userID == -1)
            std::cout << "Guest";
        else
            std::cout << userID;
        std::cout << std::endl;
        std::cout << "  Main Menu\n";
        std::cout << "1 - Employees\n";
        std::cout << "2 - Tasks\n";
        std::cout << "3 - Reports\n";
        std::cout << "4 - Change User\n";
        std::cout << "e - Exit\n";
        std::cout << std::endl;
        getline(std::cin, input);
        if (input == "1")
            employeesMenu();
        else if (input == "2")
            taskMenu();
        else if (input == "3")
            reportMenu();
        else if (input == "4")
            changeUser();
        else if (input == "e")
            return;
    }
}
