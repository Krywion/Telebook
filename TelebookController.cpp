//
// Created by Maks Krywionek on 02/03/2023.
//

#include "TelebookController.h"

TelebookController::TelebookController() {
    this->telebook = CsvManager::read();
}

void TelebookController::loop() {
    while (true) {
        showOptions();
        int choice;

        std::cin >> choice;
        executeOption(choice);
    }
}

void TelebookController::showOptions() {
    std::cout
        << "0 -  Dodaj kontakt\n"
        << "1 -  Wyszukaj kontakt po imieniu\n"
        << "2 -  Wyszukaj kontakt po numerze telefonu\n"
        << "3 -  Usuń kontakt\n"
        << "4 -  Wyjdz\n";

}

void TelebookController::executeOption(int choice) {
    switch (choice) {
        case 0:
            addContact();
            break;
        case 1:
            searchByname();
            break;
        case 2:
            searchByPhoneNumber();
            break;
        case 3:
            deleteContact();
            break;
        case 4:
            close();
            break;
    }
}

void TelebookController::addContact() {
    std::string name, phoneNumber;
    std::cout << "Wprowadź imię: ";
    std::cin >> name;
    std::cout << "Wprowadź numer telefonu: ";
    std::cin >> phoneNumber;
    std::cout << std::endl;

    telebook.addContact(name, phoneNumber);
}

void TelebookController::searchByname() {
    std::string name;
    std::cout << "Imię: ";
    std::cin >> name;

    for(Contact contact : telebook.findByName(name)) {
        std::cout << contact.toString() << std::endl;
    }

}

void TelebookController::searchByPhoneNumber() {
    std::string phoneNumber;
    std::cout << "Numer: ";
    std::cin >> phoneNumber;

    for(Contact contact : telebook.findByPhone(phoneNumber)) {
        std::cout << contact.toString() << std::endl;
    }
}

void TelebookController::deleteContact() {
    std::string name;
    std::cout << "Usuń: ";
    std::cin >> name;

    if(telebook.removeContact(name))
        std::cout << "Pomyślnie usunięto kontakt: " + name << std::endl;
    else {
        std::cout << "Nie znaleziono kontaktu: " + name << std::endl;
        std::cout << "Podobne rekordy: " << std::endl;
        for(Contact contact : telebook.findByName(name)) {
            std::cout << contact.toString() << std::endl;
        }
    }
}

void TelebookController::close() {
    CsvManager::save(telebook);
    exit(EXIT_SUCCESS);
}




