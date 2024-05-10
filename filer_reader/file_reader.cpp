/*
 * @file:         filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"

double FileReader::getData(const std::string& name){
    return this -> data[name];
} 