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
    std::map<std::string, double> data;
public:
    double getData(const std::string& name);
};

#endif // INPUT_HANDLER_HPP