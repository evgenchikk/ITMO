#pragma once

#include "string"

class User {
public:
    User(std::string name, std::string surname, std::string address, std::string passportId);

    User(std::string name, std::string surname);

    std::string *getName();

    std::string *getSurname();

    std::string *getAddress();

    std::string *getPassportId();

    bool isTrusted();

private:
    std::string *name;
    std::string *surname;
    std::string *address;
    std::string *passportId;
};
