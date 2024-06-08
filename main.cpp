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
#include <iomanip>

#include <iostream>

#include "src/static_func/static.hpp"
#include "src/filer_reader/file_reader.hpp"

using predefined_function = std::function<void(void)>;

int main(int argc, char* argv[]){
    std::cout << std::fixed << std::setprecision(15);
    const std::vector<std::string> arguments(argv, argv + argc);
    std::map<std::string, predefined_function> function_list;
    function_list["-h"] = internal::help_flag;
    function_list["-v"] = internal::version_flag;
    function_list["-m"] = internal::run_mock;
    function_list["-f"] = internal::run_flag;
    if(argc == 2){
        function_list[arguments.at(1)]();
    }else if(arguments.at(1) == "-f" && argc == 7){
        FileReader::setFile(arguments.at(2));
        FileReader::extractData(arguments.at(3), arguments.at(4), arguments.at(5), arguments.at(6));
        function_list["-f"]();
    } else {
        printf("Too many arguments or invalid flag!\n");
        function_list["-h"]();
    }
    return EXIT_SUCCESS;
}