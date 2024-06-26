/*
 * @file:         static_func/static.cpp
 * @author:       Patryk Januszewski
 * @description:  Namespace containing various static elements 
 */

#include "static.hpp"
#include "../alg/alg.hpp"
#include "../filer_reader/file_reader.hpp"
#include <cstdlib>
#include <iostream>

void internal::version_flag(){
    printf("version - 1.0\n");
}

void internal::run_flag(){
    FileReader::printTimeData();
    std::cout << "-----------------------" << std::endl;
    const map_T coordinates = internal::getX_Y(FileReader::getData(), FileReader::getTimeData());
    std::cout << "X\t" << coordinates.at("X") << std::endl;
    std::cout << "Y\t" << coordinates.at("Y")  << std::endl;
    std::cout << "Z\t" << coordinates.at("Z")  << std::endl;
}

void internal::run_mock(){
    FileReader::makeMock();
    if(FileReader::isMock) printf("Mock loaded\n");
    FileReader::printData();
    FileReader::printTimeData();
    internal::run_flag();
}

void internal::help_flag(){
    printf("Help command\n");
    printf("Help\t-h - Display help\n");
    printf("Version\t-v - Display version\n");
    printf("Mock\t-m - Preview program without any input\n");
    printf("File\t-f - [filename] [Sv]  clock - [ss mm hh]\n");
    printf(" \texample: -f brdc0940.23n 1 30 20 22 \n");
}