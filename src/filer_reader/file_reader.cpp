/*
 * @file:         src/filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"
#include "../static_func/static.hpp"

std::string FileReader::file;
std::ifstream FileReader::file_stream;
std::map<std::string, std::string> FileReader::input_date;
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
    "cic",
    "i0",   
    "crc",  
    "om",   
    "omdot",
    "idot",
    "year",
    "month",
    "day",
    "hour",
    "min",
    "sec",
    "tydz",
    "week_s",
};

bool FileReader::mockFlag = false;
std::map<std::string, double> FileReader::data;

void FileReader::setFile(const std::string i_file){
    FileReader::file = i_file;
    std::cout << "Prompted file -> " + file << std::endl;
    file_stream = std::ifstream(file);
    if(!file_stream.is_open()){
        std::cerr << file + " - not found in directory" << std::endl;
        exit(1);
    }
}

bool FileReader::isMock(){return FileReader::mockFlag;}

void FileReader::makeMock(){
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
        {FR_names[15],2.67153985179e-10},
        {FR_names[16],2023},
        {FR_names[17],4},
        {FR_names[18],4},
        {FR_names[19],1},
        {FR_names[20],15},
        {FR_names[21],0},
        {FR_names[22],2256},
        {FR_names[23],177299.999803551}
    };
}