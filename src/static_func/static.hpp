/*
 * @file:         static_func/static.hpp
 * @author:       Patryk Januszewski
 * @description:  Namespace containing various static elements 
 */

#ifndef INTERNAL_HEADER
#define INTERNAL_HEADER

#include <string>
#include <map>

namespace internal{
    void help_flag();       // Displays help options (activates when input is invalid)
    void version_flag();    // Displays version of current program
    void run_mock();        // Run program without external data .23n file
    void run_flag();        // Run program with external source or with mocked data (depends of isMock flag)
}

#endif // INTERNAL_HEADER