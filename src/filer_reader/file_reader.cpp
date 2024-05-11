/*
 * @file:         src/filer_reader/file_reader.cpp
 * @author:       Patryk Januszewski
 * @description:  File read conrtol
 */

#include "file_reader.hpp"

bool FileReader::mockFlag = false;
std::map<std::string, double> FileReader::data;

double FileReader::getData(const std::string name){
    return FileReader::data[name];
} 

bool FileReader::isMock(){return FileReader::mockFlag;}

void FileReader::makeMock(){
    FileReader::mockFlag = true;
    FileReader::data["crs"]     = 64.65625;
    FileReader::data["deln"]    = 3.68408202823e-09;
    FileReader::data["m0"]      = -3.12525956676;
    FileReader::data["cuc"]     = -3.14973294735e-06;
    FileReader::data["e"]       = 0.0126234182389;
    FileReader::data["cus"]     = 1.15595757961e-05;
    FileReader::data["a"]       = 26560136.90362;
    FileReader::data["toe"]     = 172800;
    FileReader::data["cic"]     = 6.14672899246e-08;
    FileReader::data["om0"]     = -3.01249823912;
    FileReader::data["cic"]     = -1.99303030968e-07;
    FileReader::data["i0"]      = 0.990046368914;
    FileReader::data["crc"]     = 169.5625;
    FileReader::data["om"]      = 0.944285937368;
    FileReader::data["omdot"]   = -7.41995192792e-09;
    FileReader::data["idot"]    = 2.67153985179e-10;
}