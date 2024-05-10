/*
 * @file:         input_handler/input_handler.hpp
 * @author:       Patryk Januszewski
 * @description:  Base file input control
 */

#include <string>
#include <cstdint>
#include <vector>

class InputHanler{
    const uint32_t vlaue;
    const std::vector<std::string> allowed_flags = {
        "-v",
        "-d",
        "-f",
        "-h"
    };
public:
    InputHanler();
};