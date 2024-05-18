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
    constexpr uint32_t startYear = 1980;
    constexpr uint32_t startMonth = 01;
    constexpr uint32_t startDay = 06;

    uint32_t countWeeks(std::map<std::string, double> *input_data);

    std::map<std::string, double> getX_Y(std::map<std::string, double> *input_data);
    static constexpr double GM = 3.986005e+14;
    static constexpr double omega_e = 7.2921151467e-5;
} // namespace internal

#endif // ALG_HEADER