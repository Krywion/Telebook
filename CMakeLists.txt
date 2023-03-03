cmake_minimum_required(VERSION 3.23)
project(Telebook)

set(CMAKE_CXX_STANDARD 14)

add_executable(Telebook main.cpp Contact.cpp Contact.h Telebook.cpp Telebook.h TelebookController.cpp TelebookController.h CsvManager.cpp CsvManager.h)
