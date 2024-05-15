/*
* @file main.cpp
* @author Patryk Januszewski
* Desc:
* Main executable file in program
*/

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <cstdlib>

#include <iostream>

#include "src/static_func/static.hpp"
#include "src/filer_reader/file_reader.hpp"

using predefined_function = std::function<void(void)>;

int main(int argc, char* argv[]){
    const std::vector<std::string> arguments(argv, argv + argc);
    std::map<std::string, predefined_function> function_list;
    function_list["-h"] = internal::help_flag;
    function_list["-v"] = internal::version_flag;
    function_list["-m"] = internal::run_mock;
    function_list["-f"] = internal::run_flag;
    if(argc == 2){
        function_list[arguments.at(1)]();
    }else if(arguments.at(1) == "-f" && argc == 4){
        FileReader::setFile(arguments.at(2));
        FileReader::setDate(arguments.at(3));
        function_list[arguments.at(1)]();
    } else {
        printf("Too many arguments or invalid flag!\n");
        function_list["-h"]();
    }
    return 0;
}