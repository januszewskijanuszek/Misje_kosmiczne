/*
 * @file:         src/alg/alg.hpp
 * @author:       Patryk Januszewski
 * @description:  Algorithm making whole calculating magic (main feature of the program)
 */

#ifndef ALG_HEADER
#define ALG_HEADER

#include <map>
#include <string>

using map_T = std::map<std::string, double>;

namespace internal
{
    map_T getX_Y(map_T *input_data, map_T *input_date_data);    // Getting X Y Z of the satelite (main feature of program)
    static constexpr double GM = 3.986005e+14;                  // Constant Earth weight
    static constexpr double omega_e = 7.2921151467e-5;          // How fast Earth is rotating
} // namespace internal

#endif // ALG_HEADER