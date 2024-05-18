#include "alg.hpp"

#include <iostream>

std::map<std::string, double> internal::getX_Y(std::map<std::string, double> *input_data){

    const double czas_obl = 0.0;
    double abomalia_sr = 0.0;
    double anomalia_mimosr = 0.0;
    double sin = 0.0;
    double cos = 0.0;
    double nu = 0.0;
    double anomalia_praw = 0.0;
    double anomalia_praw_pery = 0.0;
    double u_popraw = 0.0;
    double r_popraw = 0.0;
    double i_popraw = 0.0;
    double Xp = 0.0;
    double Yp = 0.0;
    double rektascencja_wenzla_popraw = 0.0;
    double X = 0.0;
    double Y = 0.0;
    double Z = 0.0;

    internal::countWeeks(input_data);

    return {{"X", 1.0},{"Y", 1.0},{"Z", 1.0}};
}

uint32_t internal::countWeeks(std::map<std::string, double> *input_data){
    const uint32_t endYear = static_cast<uint32_t>(input_data->at("year"));
    const uint32_t endMonth = static_cast<uint32_t>(input_data->at("month"));
    const uint32_t endDay = static_cast<uint32_t>(input_data->at("day"));

    const uint32_t difYear = endYear - internal::startYear;
    const uint32_t difMonth = endMonth - internal::startMonth;
    const uint32_t difDay = endDay - internal::startDay;
    std::cout << difYear << std::endl;
    return 0;
}