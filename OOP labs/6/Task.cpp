#include "Task.h"


std::string Task::statusString() {
    switch (status) {
        case Status::Open:
            return "Open";
        case Status::Active:
            return "Active";
        case Status::Resolved:
            return "Resolved";
    };
    return "ERROR";
}


Task::Task(size_t _ID, std::string _name, std::string _description, int _employeeID, size_t creatorID) :
        ID(_ID), name(_name), description(_description), employeeID(_employeeID), creationTime(time(nullptr)) {
    if (employeeID != -1)
        editorsID.insert(employeeID);

    std::string historyText = "Task created";
    history.push_back(new TimedPost(historyText, creatorID));
}


void Task::addComment(std::string text, size_t editorID) {
    comments.push_back(new TimedPost(text, employeeID));
    std::string historyText = "Comment added: \"" + text + "\"";
    history.push_back(new TimedPost(historyText, editorID));
    editorsID.insert(editorID);
}


void Task::assignEmployee(int newEmployeeID, size_t editorID) {
    std::string historyText;
    if (newEmployeeID == -1)
        historyText = "Unassigned task from " + std::to_string(employeeID);
    else
        historyText = "Reassigned from " + std::to_string(employeeID) + " to " + std::to_string(newEmployeeID);
    employeeID = newEmployeeID;
    history.push_back(new TimedPost(historyText, editorID));
    editorsID.insert(editorID);
}


void Task::changeStatus(int newStatus, size_t editorID) {
    std::string historyText = "Changed status from " + statusString() + " to ";
    switch (newStatus) {
        case 1:
            status = Status::Open;
            break;
        case 2:
            status = Status::Active;
            break;
        case 3:
            status = Status::Resolved;
            break;
    }
    historyText += statusString();
    history.push_back(new TimedPost(historyText, editorID));
    editorsID.insert(editorID);
}


size_t Task::getID() {
    return ID;
}


const std::string &Task::getName() {
    return name;
}


const std::string &Task::getDescription() {
    return description;
}


int Task::getEmployeeID() {
    return employeeID;
}


std::string Task::getStatus() {
    return statusString();
}


time_t Task::getCreationTime() {
    return creationTime;
}


time_t Task::getLastChangeTime() {
    return history[history.size() - 1]->getTime();
}


const std::vector<TimedPost *> &Task::getComments() {
    return comments;
}


const std::vector<TimedPost *> &Task::getHistory() {
    return history;
}


const std::set<size_t> &Task::getEditorsID() {
    return editorsID;
}
