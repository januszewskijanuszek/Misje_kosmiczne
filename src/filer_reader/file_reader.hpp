/*
 * @file:         filer_reader/file_reader.hpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <string>

class FileReader{
    static std::map<std::string, double> data;
    static bool isMock;
public:
    static double getData(const std::string& name);
    static void makeMock();
};

#endif // INPUT_HANDLER_HPP