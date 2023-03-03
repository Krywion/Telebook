//
// Created by Maks Krywionek on 02/03/2023.
//

#include "Telebook.h"

#ifndef TELEBOOK_CSVMANAGER_H
#define TELEBOOK_CSVMANAGER_H


class CsvManager {
private:
    static const std::string FILE_NAME;
public:
    static void save(Telebook);
    static Telebook read();
};


#endif //TELEBOOK_CSVMANAGER_H
