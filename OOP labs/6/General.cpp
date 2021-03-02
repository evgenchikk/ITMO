#define _CRT_SECURE_NO_WARNINGS // To use ctime()

#include "General.h"


std::string getDateString(time_t date) {
    return ctime(&date);
}
