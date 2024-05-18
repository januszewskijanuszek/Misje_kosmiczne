#include "alg.hpp"

#include <iostream>
#include <cmath>

double tk(std::map<std::string, double> *input_data){
    return input_data->at("week_s") - input_data->at("toe");
}

double anomaliaSrednia(std::map<std::string, double> *input_data){
    const double n0 = sqrt(internal::GM / pow(input_data->at("a"), 3));
    const double n = n0 + input_data->at("deln");
    return input_data->at("m0") + n * tk(input_data);
}

std::map<std::string, double> internal::getX_Y(std::map<std::string, double> *input_data){

    double abomalia_sr = anomaliaSrednia(input_data);
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

    std::cout << abomalia_sr << std::endl;

    return {{"X", 1.0},{"Y", 1.0},{"Z", 1.0}};
}