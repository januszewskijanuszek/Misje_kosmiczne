/*
* @file main.cpp
* @author Patryk Januszewski
* Desc:
* Main executable file in program
*/


#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    uint32_t v_value = 0;

    // Loop through command line arguments
    for(int i = 1 ; i < argc ; i++){
        string arg = argv[i];
        if(arg == "-v"){
            if(i + 1 < argc){
                v_value = stoi(argv[i + 1]);
                i++;
            } else {
                cerr << "Error: -v flag requires a value." << endl;
                return 1;
            }
        }
    }
    cout << "Value of -v flag: " << v_value << endl;
    return 0;
}