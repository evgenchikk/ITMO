#include "Report.h"


Report::Report(size_t _authorID) :
        authorID(_authorID) {}

void Report::addText(std::string newText) {
    text += "\n" + newText;
}


void Report::addTask(size_t taskID) {
    resolvedTasks.push_back(taskID);
}


size_t Report::getAuthorID() {
    return authorID;
}


std::string Report::getText() {
    return text;
}


const std::vector<size_t> &Report::getTasks() {
    return resolvedTasks;
}
