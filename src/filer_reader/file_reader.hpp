/*
 * @file:         src/filer_reader/file_reader.hpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <array>

using map_T = std::map<std::string, double>;

class FileReader{
    static map_T data;
    static std::string file;
    static bool mockFlag;
    static std::ifstream file_stream;
    static constexpr uint16_t ELEMENTS_COUNT = 24;
    static std::map<std::string, std::string> input_date;

    static inline constexpr uint16_t LINE_LENGHT = 78;
    static inline constexpr uint16_t DATA_CHUNK = 19;
public:
    static inline void setYear(const std::string i_d){input_date["year"] = i_d;};
    static inline void setMonth(const std::string i_d){input_date["month"] = i_d;};
    static inline void setDay(const std::string i_d){input_date["day"] = i_d;};
    static inline void setHour(const std::string i_d){input_date["hour"] = i_d;};
    static inline void setMinute(const std::string i_d){input_date["min"] = i_d;};
    static inline void setSec(const std::string i_d){input_date["sec"] = i_d;};
    static inline std::string getFile() {return file;}
    static inline std::string getDate(const std::string inp) {return input_date[inp];}

    static void setFile(const std::string i_file);

    static inline map_T* getData(){return &data;};     // Getting data from static map (mock/actual data)
    static void makeMock();                             // Creates mock for testing purposes
    static bool isMock();                               // Check if data created are mocked
    static const std::array<std::string, ELEMENTS_COUNT> FR_names;
};

#endif // INPUT_HANDLER_HPP