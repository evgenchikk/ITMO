#include "TimedPost.h"

TimedPost::TimedPost(std::string _text, size_t _authorId) :
        text(_text), authorId(_authorId), postTime(time(NULL)) {}

const std::string &TimedPost::getText() {
    return text;
}

size_t TimedPost::getAuthorId() {
    return authorId;
}

time_t TimedPost::getTime() {
    return postTime;
}
