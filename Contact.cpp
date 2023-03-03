//
// Created by Maks Krywionek on 01/03/2023.
//
#include <iostream>
#include "Contact.h"
Contact::Contact(std::string name, std::string phoneNumber) {
    this->name = name;
    this->phoneNumber = phoneNumber;
}

std::string Contact::getName() const {
    return this->name;
}

void Contact::setName(std::string name) {
    this->name = name;
}

std::string Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

Contact::Contact() {

}

std::string Contact::toCSV() const {
    std::string csvContact = this->name + ";" + this->phoneNumber + "\n";
    return csvContact;
}

std::string Contact::toString() const{
    return  "Imię: " + this->name + ", Numer: " + this->phoneNumber;
}
