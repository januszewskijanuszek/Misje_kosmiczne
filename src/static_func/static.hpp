/*
 * @file:         static_func/static.hpp
 * @author:       Patryk Januszewski
 * @description:  Namespace containing various static elements 
 */

#ifndef INTERNAL_HEADER
#define INTERNAL_HEADER

#include <string>
#include <map>

using field_name = std::string;

namespace internal{
    static std::map<field_name, std::string> raw_input;
    void help_flag();
    void version_flag();
    void run_flag();
}

#endif // INTERNAL_HEADER