//
// Created by Maks Krywionek on 01/03/2023.
//
#include "string"

#ifndef TELEBOOK_CONTACT_H
#define TELEBOOK_CONTACT_H


class Contact {
private:
    std::string name;
    std::string phoneNumber;
public:
    Contact();
    Contact(std::string name, std::string phoneNumber);

    std::string getName() const;
    void setName( std::string name);

    std::string getPhoneNumber() const;
    void setPhoneNumber( std::string phoneNumber);

    std::string toCSV() const;

    std::string toString() const;

};


#endif //TELEBOOK_CONTACT_H
