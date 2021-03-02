#pragma once

#include "TimedPost.h"
#include <vector>
#include <set>

class Task {
private:
    size_t Id;
    std::string name;
    std::string description;
    int employeeId;
    enum class Status {
        Open,
        Active,
        Resolved
    } status = Status::Open;

    time_t creationTime;
    std::vector<TimedPost *> comments;
    std::vector<TimedPost *> history;

    std::set<size_t> editorsId;

    std::string statusString();

public:
    Task(size_t _Id, std::string _name, std::string _description, int _employeeId, size_t creatorId);

    void addComment(std::string text, size_t editorId);

    void assignEmployee(int newEmployeeId, size_t editorId);

    void changeStatus(int newStatus, size_t editorId);

    size_t getId();

    const std::string &getName();

    const std::string &getDescription();

    int getEmployeeId();

    std::string getStatus();

    time_t getCreationTime();

    time_t getLastChangeTime();

    const std::vector<TimedPost *> &getComments();

    const std::vector<TimedPost *> &getHistory();

    const std::set<size_t> &getEditorsId();
};
