#include "alg.hpp"

#include <iostream>
#include <cmath>

constexpr double M_Pi = 3.14159265358979323846;

double tk(map_T *input_data, map_T *input_date_data){
    return input_date_data->at("week_s") - input_data->at("toe");
}

double anomaliaSrednia(map_T *input_data, map_T *input_date_data){
    const double n0 = sqrt(internal::GM / pow(input_data->at("a"), 3));
    const double n = n0 + input_data->at("deln");
    return input_data->at("m0") + n * tk(input_data, input_date_data);
}

// -- LTS --

double anomaliaMimosr(const double &anomalia_sr, const double &e,const uint32_t iteracions = 100){
    double Ek = 0;
    for(uint32_t i = 0 ; i < iteracions ; i++)
        Ek = anomalia_sr + e * sin(Ek);
    return Ek;
}

map_T internal::getX_Y(map_T *input_data, map_T *input_date_data){
    double abomalia_sr = anomaliaSrednia(input_data, input_date_data);
    double anomalia_mimosr = anomaliaMimosr(abomalia_sr, input_data -> at("e"));
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

    std::cout << anomalia_mimosr << std::endl;

    return {{"X", 1.0},{"Y", 1.0},{"Z", 1.0}};
}