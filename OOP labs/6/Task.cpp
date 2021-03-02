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

Task::Task(size_t _Id, std::string _name, std::string _description, int _employeeId, size_t creatorId) :
        Id(_Id), name(_name), description(_description), employeeId(_employeeId), creationTime(time(nullptr)) {
    if (employeeId != -1)
        editorsId.insert(employeeId);

    std::string historyText = "Task created";
    history.push_back(new TimedPost(historyText, creatorId));
}

void Task::addComment(std::string text, size_t editorId) {
    comments.push_back(new TimedPost(text, employeeId));
    std::string historyText = "Comment added: \"" + text + "\"";
    history.push_back(new TimedPost(historyText, editorId));
    editorsId.insert(editorId);
}

void Task::assignEmployee(int newEmployeeId, size_t editorId) {
    std::string historyText;
    if (newEmployeeId == -1)
        historyText = "Unassigned task from " + std::to_string(employeeId);
    else
        historyText = "Reassigned from " + std::to_string(employeeId) + " to " + std::to_string(newEmployeeId);
    employeeId = newEmployeeId;
    history.push_back(new TimedPost(historyText, editorId));
    editorsId.insert(editorId);
}

void Task::changeStatus(int newStatus, size_t editorId) {
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
    history.push_back(new TimedPost(historyText, editorId));
    editorsId.insert(editorId);
}

size_t Task::getId() {
    return Id;
}

const std::string &Task::getName() {
    return name;
}

const std::string &Task::getDescription() {
    return description;
}

int Task::getEmployeeId() {
    return employeeId;
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

const std::set<size_t> &Task::getEditorsId() {
    return editorsId;
}
