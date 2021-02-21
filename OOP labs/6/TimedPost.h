#pragma once

#include <time.h>
#include <string>


class TimedPost {
    std::string text;
    size_t authorID;
    time_t postTime;

public:
    TimedPost(std::string _text, size_t _authorID);

    const std::string &getText();

    size_t getAuthorID();

    time_t getTime();
};
