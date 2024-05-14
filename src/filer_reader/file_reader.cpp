/*
 * @file:         src/filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"
#include "../static_func/static.hpp"

bool FileReader::mockFlag = false;
std::map<std::string, double>* FileReader::data = nullptr;

double FileReader::getData(const std::string key){
    return FileReader::data->at(key);
} 

bool FileReader::isMock(){return FileReader::mockFlag;}

void FileReader::makeMock(){
    FileReader::mockFlag = true;
    FileReader::data = &internal::mocked_data;
}