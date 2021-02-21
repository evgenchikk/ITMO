#pragma once

#include <string>
#include <vector>


class Report {
    size_t authorID;
    std::string text;
    std::vector<size_t> resolvedTasks;

public:
    Report(size_t _authorID);

    void addText(std::string newText);

    void addTask(size_t taskID);

    size_t getAuthorID();

    std::string getText();

    const std::vector<size_t> &getTasks();
};
