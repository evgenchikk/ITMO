#include "User.h"

User::User(std::string name, std::string surname, std::string address, std::string passportId) {
    this->name = &name;
    this->surname = &surname;
    this->address = &address;
    this->passportId = &passportId;
}

User::User(std::string name, std::string surname) {
    this->name = &name;
    this->surname = &surname;
    this->address = nullptr;
    this->passportId = nullptr;
}

std::string *User::getName() {
    return name;
}

std::string *User::getSurname() {
    return surname;
}

std::string *User::getAddress() {
    return address;
}

std::string *User::getPassportId() {
    return passportId;
}

bool User::isTrusted() {
    return address != nullptr && passportId != nullptr;
}
