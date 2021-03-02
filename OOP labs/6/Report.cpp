#include "Report.h"

Report::Report(size_t _authorId) :
        authorId(_authorId) {}

void Report::addText(std::string newText) {
    text += "\n" + newText;
}

void Report::addTask(size_t taskId) {
    resolvedTasks.push_back(taskId);
}

size_t Report::getAuthorId() {
    return authorId;
}

std::string Report::getText() {
    return text;
}

const std::vector<size_t> &Report::getTasks() {
    return resolvedTasks;
}