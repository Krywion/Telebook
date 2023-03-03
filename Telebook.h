//
// Created by Maks Krywionek on 01/03/2023.
//
#include <iostream>
#include <map>
#include "Contact.h"
#include "vector"

#ifndef TELEBOOK_TELEBOOK_H
#define TELEBOOK_TELEBOOK_H


class Telebook {
private:
    std::map<std::string, Contact> contacts;
public:
    Telebook();
    Telebook(std::map<std::string, Contact> contacts);

    bool addContact(std::string name, std::string phoneNumber);
    bool removeContact(std::string name);

    std::vector<Contact> findByName(std::string name) const;
    std::vector<Contact> findByPhone(std::string phoneNumber) const;

    std::map<std::string, Contact> getContacts() const;

    void setContacts(const std::map<std::string, Contact> &contacts);


};



#endif //TELEBOOK_TELEBOOK_H
