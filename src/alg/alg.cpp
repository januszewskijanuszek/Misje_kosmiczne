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

double anomaliaMimosr(const double &anomalia_sr, const double &e,const uint32_t iteracions = 100){
    double Ek = 0;
    for(uint32_t i = 0 ; i < iteracions ; i++)
        Ek = anomalia_sr + e * sin(Ek);
    return Ek;
}

double anomaliaPrawdziwa(const double &momosrod, const double &e){
    return (2 * atan2(sqrt(1 + e) * sin(momosrod / 2), sqrt(1 - e) * cos(momosrod / 2)));
}

double Vk_f(const double &momosrod, const double &e){
    double sin_E = sin(momosrod);
    double cos_E = cos(momosrod);
    double sqrt_term = sqrt(1 - pow(e, 2));
    
    double Vk = atan2(sqrt_term * sin_E, cos_E - e);
    
    return Vk;
}

double d_creator(const double &payload_1, const double &payload_2, const double &Fk){
    return payload_1 * cos(2 * Fk) + payload_2 * sin(2 * Fk);
}

map_T internal::getX_Y(map_T *input_data, map_T *input_date_data){
    const double &e = input_data -> at("e");
    double abomalia_sr = anomaliaSrednia(input_data, input_date_data);
    double anomalia_mimosr = anomaliaMimosr(abomalia_sr, e);
    double nu = anomaliaPrawdziwa(anomalia_mimosr, e);
    double anomalia_praw_pery = Vk_f(anomalia_mimosr, e);
    double Fk = anomalia_praw_pery + input_data->at("om");
    double u_popraw = Fk + d_creator(input_data->at("cuc"), input_data->at("cus"), Fk);
    double r_popraw = input_data->at("a") * (1 - e * cos(anomalia_mimosr)) + d_creator(input_data->at("crc"), input_data->at("crs"), Fk);
    double i_popraw = input_data->at("i0") + input_data->at("idot") * tk(input_data, input_date_data) + d_creator(input_data->at("cic"), input_data->at("cis"), Fk);
    double Xp = 0.0;
    double Yp = 0.0;
    double rektascencja_wenzla_popraw = 0.0;
    double X = 0.0;
    double Y = 0.0;
    double Z = 0.0;

    std::cout << u_popraw << std::endl;
    std::cout << r_popraw << std::endl;
    std::cout << i_popraw << std::endl;

    return {{"X", 1.0},{"Y", 1.0},{"Z", 1.0}};
}