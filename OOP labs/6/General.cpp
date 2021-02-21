#include "General.h"


std::string getDateString(time_t date) {
    return ctime(&date);
}