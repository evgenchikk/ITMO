#pragma once

#include <time.h>
#include <string>


class TimedPost {
    std::string text;
    size_t authorId;
    time_t postTime;

public:
    TimedPost(std::string _text, size_t _authorId);

    const std::string &getText();

    size_t getAuthorId();

    time_t getTime();
};
