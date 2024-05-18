/*
 * @file:         src/alg/alg.hpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#ifndef ALG_HEADER
#define ALG_HEADER

#include <map>
#include <string>

namespace internal
{
    std::map<std::string, double> getX_Y(std::map<std::string, double> *input_data);
    static constexpr double GM = 3.986005e+14;
    static constexpr double omega_e = 7.2921151467e-5;
} // namespace internal

#endif // ALG_HEADER