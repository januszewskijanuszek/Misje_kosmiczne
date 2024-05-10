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

#include "static_func/static.hpp"

using namespace std;
using predefined_function = function<void(void)>;

int main(int argc, char* argv[]){
    const std::vector<std::string> arguments(argv, argv + argc);
    std::map<std::string, predefined_function> function_list;
    function_list["-h"] = internal::help_flag;
    function_list["-v"] = internal::version_flag;
    function_list["-f"] = internal::run_flag;

    return 0;
}