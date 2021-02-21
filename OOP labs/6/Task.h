#pragma once

#include "TimedPost.h"
#include <vector>
#include <set>


class Task {
private:
    size_t ID;
    std::string name;
    std::string description;
    int employeeID;
    enum class Status {
        Open,
        Active,
        Resolved
    } status = Status::Open;

    time_t creationTime;
    std::vector<TimedPost *> comments;
    std::vector<TimedPost *> history;

    std::set<size_t> editorsID;

    std::string statusString();

public:
    Task(size_t _ID, std::string _name, std::string _description, int _employeeID, size_t creatorID);

    void addComment(std::string text, size_t editorID);

    void assignEmployee(int newEmployeeID, size_t editorID);

    void changeStatus(int newStatus, size_t editorID);

    size_t getID();

    const std::string &getName();

    const std::string &getDescription();

    int getEmployeeID();

    std::string getStatus();

    time_t getCreationTime();

    time_t getLastChangeTime();

    const std::vector<TimedPost *> &getComments();

    const std::vector<TimedPost *> &getHistory();

    const std::set<size_t> &getEditorsID();
};
