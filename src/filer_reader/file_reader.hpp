/*
 * @file:         src/filer_reader/file_reader.hpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <string>
#include <fstream>

class FileReader{
    static std::map<std::string, double> data;
    static std::string file;
    static std::string date;
    static bool mockFlag;
public:
    static inline void setDate(const std::string i_date){date = i_date;};
    static inline std::string getFile() {return file;}
    static inline std::string getDate() {return date;}

    static void setFile(const std::string i_file);

    static double getData(const std::string name);     // Getting data from static map (mock/actual data)
    static void makeMock();                             // Creates mock for testing purposes
    static bool isMock();                               // Check if data created are mocked
    static void loadFromFile(const std::string& filename);                             // Reads data from the specified file provided with -f flag
};

#endif // INPUT_HANDLER_HPP