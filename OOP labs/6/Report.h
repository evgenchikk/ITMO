#pragma once

#include <string>
#include <vector>

class Report {
    size_t authorId;
    std::string text;
    std::vector<size_t> resolvedTasks;

public:
    Report(size_t _authorId);

    void addText(std::string newText);

    void addTask(size_t taskId);

    size_t getAuthorId();

    std::string getText();

    const std::vector<size_t> &getTasks();
};
