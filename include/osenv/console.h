#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "../system/sys.h"


//#define SERIAL_ENABLED 

#ifndef SERIAL_ENABLED
    #define Printf std::printf
    #define Str_toI(a) std::stoi(a)
    // Println
    

    // Error
    void ERROR(std::string msg) {
        std::cerr << msg << std::endl;
    }
#endif
template<typename T>
void Println(T const& msg)
{
    std::cout << msg << std::endl;
}

// void printByte(BYTE b) {
//     for (int i = 0; i < 8; i++) {
//         std::cout << b.data[7-i];
//     }
//     std::cout << std::endl;
// }

std::string toUpper(std::string s) {
    std::string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        res += std::toupper(s.at(i));
    }
    return res;
}

bool Active_Console = false;


#endif