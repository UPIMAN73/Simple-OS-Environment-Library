#ifndef SYS_H
#define SYS_H

//#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
//#include <Serial.h>

#include "math.h"
#include <vector>

// // A single byte
// struct BYTE {
//     bool data[8];
// };

// struct BYTE_16 {
//     bool data[16];
// };


// void byteShiftRight(BYTE * b, uint8_t val) {
//     BYTE * a = new BYTE();
//     for (int i = 0; i < val; i++) {
//         a->data[7-i] = b->data[i];
//     }
//     b = a;
// }

// BYTE convByte(std::string val) {
//     BYTE result;
//     for (int i = 0; i < 8; i++) {
//         if (val.at(i) == '\0') {
//             byteShiftRight(&result, val.length());
//             break;
//         }

//         if (val.at(i) == '1') {
//             result.data[i] = true;
//         }
//     }
//     return result;
// }


#endif