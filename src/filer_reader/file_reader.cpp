/*
 * @file:         src/filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"
#include "../static_func/static.hpp"
#include <iostream>
using namespace std;

std::string FileReader::file;
std::string FileReader::date;

bool FileReader::mockFlag = false;
std::map<std::string, double> FileReader::data;

double FileReader::getData(const std::string key){
    return FileReader::data[key];
} 
void FileReader::setFile(const std::string i_file){
    FileReader::file = i_file;
    cout << file << endl;
}
bool FileReader::isMock(){return FileReader::mockFlag;}

void FileReader::makeMock(){
    FileReader::mockFlag = true;
    FileReader::data = {
        {"crs",     64.65625},
        {"deln",    3.68408202823e-09},
        {"m0",     -3.12525956676},
        {"cuc",     -3.14973294735e-06},
        {"e",       0.0126234182389},
        {"cus",     1.15595757961e-05},
        {"a",       26560136.90362},
        {"toe",     172800},
        {"cic",     6.14672899246e-08},
        {"om0",     -3.01249823912},
        {"cic",     -1.99303030968e-07},
        {"i0",      0.990046368914},
        {"crc",     169.5625},
        {"om",      0.944285937368},
        {"omdot",   -7.41995192792e-09},
        {"idot",    2.67153985179e-10}
    };
}

void FileReader::loadFromFile(const std::string& filename){
    
}