/*
 * @file:         static_func/static.cpp
 * @author:       Patryk Januszewski
 * @description:  Namespace containing various static elements 
 */

#include "static.hpp"
#include <cstdlib>

void internal::version_flag(){
    printf("version - 1.0\n");
}

void internal::help_flag(){
    printf("Help command\n");
    printf("Help            -h - Display help\n");
    printf("Version         -v - Display version\n");
    printf("File            -f - [filename] [date dd-mm-rrrr]\n");
    printf("                example: -f brdc0940.23n 15-10-2015 \n");
}

void internal::run_flag(){
    // Future implementation
}