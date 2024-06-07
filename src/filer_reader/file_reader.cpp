/*
 * @file:         src/filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"
#include "../static_func/static.hpp"
#include <cstdlib>
#include <string>

std::string FileReader::file;
std::ifstream FileReader::file_stream;
std::map<std::string, std::string> FileReader::input_date;
std::map<std::string, double> FileReader::data;
std::map<std::string, double> FileReader::date_data;

const std::array<std::string, FileReader::ELEMENTS_COUNT> FileReader::FR_names = {
    "crs",
    "deln",
    "m0",  
    "cuc", 
    "e",   
    "cus", 
    "a",   
    "toe",    
    "cic",
    "om0",
    "cis",
    "i0",   
    "crc",  
    "om",   
    "omdot",
    "idot"
};

const std::array<std::string, 8> FileReader::dates_array = {
    "year",
    "month",
    "day",
    "hour",
    "min",
    "sec",
    "tydz",
    "week_s"
};

bool FileReader::mockFlag = false;

void FileReader::setFile(const std::string i_file) {
    FileReader::file = i_file;
    std::cout << "Prompted file -> " + file << std::endl;
    file_stream = std::ifstream(file);
    if (!file_stream.is_open()) {
        std::cerr << file + " - not found in directory" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void FileReader::extractData(const std::string &sv, const std::string &seconds, const std::string &minutes, const std::string &hours){
    if (!FileReader::file_stream.is_open()) {
        std::cerr << "First set the file" << std::endl;
        exit(EXIT_FAILURE);
    }
    try{
        const double sec = std::stod(seconds);
        const double min = std::stod(minutes);
        const uint32_t hour = std::stoul(hours);
        const uint32_t dec_sv = std::stoul(sv);
        if(sec  >= 60 || sec < 0 || min >= 60 || min < 0 || hour >= 24 || hour < 0){
            std::cerr << "Invalid time format" << std::endl;
            exit(EXIT_FAILURE);
        }
        printf("\n");
        std::string line;
        for(uint8_t i = 0; std::getline(FileReader::file_stream, line) && i < 7 ; i++){
            std::cout << line << std::endl;
            if(i == 5){
                FileReader::date_data["tydz"] = std::stod(line.substr(55, 4));
            }
        }
        uint16_t counter = 0;
        while (std::getline(file_stream, line)){
            if(counter == FileReader::CHUNK_ROWS) counter = 0;
            if(counter == 0){
                if( std::stoul(line.substr(0,2)) == dec_sv && 
                    std::stoul(line.substr(12, 2)) <= hour &&
                    std::stoul(line.substr(12, 2)) + 2 > hour){
                        
                    std::cout << line << std::endl;
                    std::cout << line.substr(12, 10) << std::endl;
                }
            }
            counter ++;
        }
    }catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
}

void FileReader::makeMock() {
    FileReader::mockFlag = true;
    FileReader::data = {
        {FR_names[0], 64.65625},
        {FR_names[1], 3.68408202823e-09},
        {FR_names[2], -3.12525956676},
        {FR_names[3], -3.14973294735e-06},
        {FR_names[4], 0.0126234182389},
        {FR_names[5], 1.15595757961e-05},
        {FR_names[6], 26560136.90362},
        {FR_names[7], 172800},
        {FR_names[8], 6.14672899246e-08},
        {FR_names[9], -3.01249823912},
        {FR_names[10],-1.99303030968e-07},
        {FR_names[11],0.990046368914},
        {FR_names[12],169.5625},
        {FR_names[13],0.944285937368},
        {FR_names[14],-7.41995192792e-09},
        {FR_names[15],2.67153985179e-10}
    };
    FileReader::date_data = {
        {dates_array[0], 2023},
        {dates_array[1], 4},
        {dates_array[2], 4},
        {dates_array[3], 1},
        {dates_array[4], 15},
        {dates_array[5], 0},
        {dates_array[6], 2256},
        {dates_array[7], 177299.999803551}
    };
}