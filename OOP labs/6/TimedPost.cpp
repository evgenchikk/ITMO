#include "TimedPost.h"


TimedPost::TimedPost(std::string _text, size_t _authorID) :
        text(_text), authorID(_authorID), postTime(time(NULL)) {}

const std::string &TimedPost::getText() {
    return text;
}


size_t TimedPost::getAuthorID() {
    return authorID;
}


time_t TimedPost::getTime() {
    return postTime;
}
