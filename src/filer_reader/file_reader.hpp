/*
 * @file:         src/filer_reader/file_reader.hpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <string>

class FileReader{
    static std::map<std::string, double> data;
    static bool mockFlag;
public:
    static double getData(const std::string name);     // Getting data from static map (mock/actual data)
    static void makeMock();                             // Creates mock for testing purposes
    static bool isMock();                               // Check if data created are mocked
    static bool readData();                             // Reads data from the specified file provided with -f flag
};

#endif // INPUT_HANDLER_HPP