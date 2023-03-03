//
// Created by Maks Krywionek on 01/03/2023.
//

#include "Telebook.h"
Telebook::Telebook() {

}

Telebook::Telebook(std::map<std::string, Contact> contacts) {
    this->contacts = contacts;
}

bool Telebook::addContact(std::string name, std::string phoneNumber) {
    if ( name.empty() || phoneNumber.empty() ) {
        throw std::invalid_argument("Imię ani numer nie może być puste!");
    }
    if( !contacts.count(name) ) {
        Contact contact(name, phoneNumber);
        this->contacts.insert(std::pair<std::string, Contact>(name, contact));
        return true;
    }
    else {
        return false;
    }
}

bool Telebook::removeContact(std::string name) {
    if(contacts.count(name)){
        contacts.erase(name);
        return true;
    }
    else {
        return false;
    }


}

std::vector<Contact> Telebook::findByName(std::string name) const{
    std::vector<Contact> result;
    for(auto const& x : contacts) {
        if(x.first.find(name) != std::string::npos){
            result.push_back(x.second);
        }
    }

    return result;
}

std::vector<Contact> Telebook::findByPhone(std::string phoneNumber) const {
    std::vector<Contact> result;
    for(auto const& x : contacts) {
        if(x.second.getPhoneNumber().find(phoneNumber) != std::string::npos){
            result.push_back(x.second);
        }
    }

    return result;
}

std::map<std::string, Contact> Telebook::getContacts() const {
    return this->contacts;
}

void Telebook::setContacts(const std::map<std::string, Contact> &contacts) {
    this->contacts = contacts;
}
