//
// Created by Maks Krywionek on 02/03/2023.
//

#include "CsvManager.h"
#include "fstream"

const std::string CsvManager::FILE_NAME = "telebook.csv";

void CsvManager::save(Telebook telebook) {
    std::ofstream file;
    file.open(FILE_NAME);

    for (auto const& x : telebook.getContacts()) {
        file << x.second.toCSV() << std::endl;
    }
    file.close();
}

Telebook CsvManager::read() {
    Telebook telebook;
    std::ifstream file;
    file.open(FILE_NAME);

    if(file.is_open()){

        std::string line;
        std::string delimeter = ";";
        std::string token;
        size_t pos = 0;

        while(std::getline(file, line) && !(line.empty())){
            std::string name;
            std::string phoneNumber;

            pos = line.find(delimeter);
            token = line.substr(0, pos);
            name = token;
            line.erase(0, pos + delimeter.length());
            phoneNumber = line;

            telebook.addContact(name, phoneNumber);
        }
    }else {
        //nothing just return empty telebook
    }

    return telebook;
}
