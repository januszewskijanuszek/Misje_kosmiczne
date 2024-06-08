/*
 * @file:         src/filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"
#include "../static_func/static.hpp"
#include <cstdlib>
#include <string>
#include <cmath>

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

double FileReader::extractNumber(const std::string &string){
    std::string coppy = string;
    size_t position = coppy.find('D');
    if (position != std::string::npos) {
        coppy.replace(position, 1, "E");
        position += 1;
    }
    return std::stod(coppy);
}

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
        static double a0;
        static double a1;
        static double a2;

        const double sec = std::stod(seconds);
        const uint32_t min = std::stoul(minutes);
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
        uint16_t* counter = new uint16_t(0);
        bool* rowFound = new bool(false);
        
        while (std::getline(file_stream, line)){
            if(*counter == FileReader::CHUNK_ROWS) *counter = 0;
            if(*counter == 0){
                if( std::stoul(line.substr(0,2)) == dec_sv && 
                    std::stoul(line.substr(12, 2)) <= hour &&
                    std::stoul(line.substr(12, 2)) + 2 > hour){
                    *rowFound = true;
                    std::cout << line << std::endl;
                    date_data["year"] = std::stod("20" + line.substr(3,2));
                    date_data["month"] = std::stod(line.substr(6,2));
                    date_data["day"] = std::stod(line.substr(9,2));
                    date_data["hour"] = hour;
                    date_data["min"] = min;
                    date_data["sec"] = sec;
                    date_data["week_s"] = 0.0;
                    a0 = extractNumber(
                        line.substr(FileReader::PADDING + FileReader::DATA_CHUNK, 
                        FileReader::DATA_CHUNK));
                    a1 = extractNumber(
                        line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * 2, 
                        FileReader::DATA_CHUNK));
                    a2 = extractNumber(
                        line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * 3, 
                        FileReader::DATA_CHUNK));
                }
            }
            if(*rowFound){
                std::getline(file_stream, line);
                std::cout << line << std::endl;
                FileReader::data["crs"] = extractNumber(
                    line.substr(FileReader::PADDING + FileReader::DATA_CHUNK, 
                    FileReader::DATA_CHUNK));
                FileReader::data["deln"] = extractNumber(
                    line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * 2, 
                    FileReader::DATA_CHUNK));
                FileReader::data["m0"] = extractNumber(
                    line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * 3, 
                    FileReader::DATA_CHUNK));
                
                std::getline(file_stream, line);
                std::cout << line << std::endl;
                for(uint32_t i = 3 ; i < 7 ; i++){
                    FileReader::data[FR_names.at(i)] = extractNumber(
                        line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * (i - 3), 
                        FileReader::DATA_CHUNK));
                }
                std::getline(file_stream, line);
                std::cout << line << std::endl;
                for(uint32_t i = 7 ; i < 11 ; i++){
                    FileReader::data[FR_names.at(i)] = extractNumber(
                        line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * (i - 7), 
                        FileReader::DATA_CHUNK));
                }
                std::getline(file_stream, line);
                std::cout << line << std::endl;
                for(uint32_t i = 11 ; i < 15 ; i++){
                    FileReader::data[FR_names.at(i)] = extractNumber(
                        line.substr(FileReader::PADDING + FileReader::DATA_CHUNK * (i - 11), 
                        FileReader::DATA_CHUNK));
                }
                std::getline(file_stream, line);
                std::cout << line << std::endl;
                FileReader::data["idot"] = extractNumber(
                    line.substr(FileReader::PADDING, FileReader::DATA_CHUNK));
                FileReader::data["a"] = std::pow(FileReader::data["a"], 2);
                const double t = FileReader::data["toe"] + hour * 3600 + min * 60 + sec;
                const double toc = FileReader::data["toe"] + hour * 3600 + min * 60 + sec;
                const double sv_clock_correection = a0 + a1 * (t - toc) + a2 * std::pow((t - toc), 2);
                FileReader::date_data["week_s"] = FileReader::data["toe"] + hour * 3600 + min * 60 + sec + sv_clock_correection;
                break;
            }
            (*counter) ++;
        }
        delete rowFound;
        delete counter;
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