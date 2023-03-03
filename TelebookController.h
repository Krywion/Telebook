//
// Created by Maks Krywionek on 02/03/2023.
//

#ifndef TELEBOOK_TELEBOOKCONTROLLER_H
#define TELEBOOK_TELEBOOKCONTROLLER_H

#include "Telebook.h"
#include "CsvManager.h"

class TelebookController {
private:
    Telebook telebook;

    void showOptions();
    void executeOption(int choice);

    void addContact();
    void searchByname();
    void searchByPhoneNumber();
    void deleteContact();
    void close();
public:
    TelebookController();

    void loop();


};


#endif //TELEBOOK_TELEBOOKCONTROLLER_H
