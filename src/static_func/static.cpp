/*
 * @file:         static_func/static.cpp
 * @author:       Patryk Januszewski
 * @description:  Namespace containing various static elements 
 */

#include "static.hpp"
#include "../filer_reader/file_reader.hpp"
#include <cstdlib>

void internal::version_flag(){
    printf("version - 1.0\n");
}

void internal::run_mock(){
    FileReader::makeMock();
    if(FileReader::isMock) printf("Mock loaded succesfully!\n");
}

void internal::help_flag(){
    printf("Help command\n");
    printf("Help            -h - Display help\n");
    printf("Version         -v - Display version\n");
    printf("Mock            -m - Preview program without any input\n");
    printf("File            -f - [filename] [date dd-mm-rrrr]\n");
    printf("                example: -f brdc0940.23n 15-10-2015 \n");
}

void internal::run_flag(){
    // Future implementation
}

std::map<std::string, double> internal::mocked_data = {
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