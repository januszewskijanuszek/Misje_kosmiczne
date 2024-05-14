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