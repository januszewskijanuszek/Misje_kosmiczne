/*
 * @file:         src/filer_reader/file_reader.hpp
 * @author:       Patryk Januszewski
 * @description:  Utility class for file read conrtol
 */

#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <iomanip>

using map_T = std::map<std::string, double>;

class FileReader{
    static map_T data;        // Output data from filereader with orbit info
    static map_T date_data;   // Output data from file and IO about date
    // ---------------------- //
    static std::string file;
    static bool mockFlag;
    static constexpr uint16_t ELEMENTS_COUNT = 16;
    static std::map<std::string, std::string> input_date;   

    static inline constexpr uint16_t LINE_LENGHT = 78;      // Lenght of the whole section of elements in ".23n" file
    static inline constexpr uint16_t DATA_CHUNK = 19;       // Lenght of the one element in the file ".23n"
    static inline constexpr uint16_t DATE_CHUNK = 10;       // Lenght of the one element in the file ".23n"
    static inline constexpr uint16_t CHUNK_ROWS = 8;        // Lenght of rows in each chunk
    static inline constexpr uint16_t PADDING = 3;           // Lenght of padding at the beginning
    static double extractNumber(const std::string &string);
public:
    /*
        Bunch of inlined functiuons, mostly getter and setters. 
        If complex thing is going on here then explenation will be in following line.
    */
    static std::ifstream file_stream;
    static inline std::string getDate(const std::string inp) {return input_date[inp];}

    static inline map_T* getData(){return &data;};                  // Getting addres for actual data
    static inline map_T* getTimeData(){return &date_data;};

    // Printing out Time Data to std out
    static inline void printTimeData(){                             
        std::cout << std::fixed << std::setprecision(0);
        for(const auto &element : FileReader::dates_array){
            if(element == "week_s") std::cout << std::fixed << std::setprecision(15);
            std::cout << element << "\t" << date_data.at(element) << std::endl;
        }
        std::cout << std::fixed << std::setprecision(15);
    }

    // Printing out Data to std out
    static inline void printData(){
        for(const auto &element : FileReader::FR_names){
            std::cout << element << "\t" << data.at(element) << std::endl;
        }
    }       

    static void setFile(const std::string i_file);                  // Setting file for Read status
    static void extractData(const std::string &sv, const std::string &seconds, const std::string &minutes, const std::string &hours);

    static void makeMock();                                         // Creates mock for testing purposes
    static inline bool isMock() { return FileReader::mockFlag; }    // Check if data created are mocked
    static const std::array<std::string, ELEMENTS_COUNT> FR_names;  // List of elements names (used for easy printout all required data to check)
    static const std::array<std::string, 8> dates_array;            // Set of names for the date elements
};

#endif // INPUT_HANDLER_HPP