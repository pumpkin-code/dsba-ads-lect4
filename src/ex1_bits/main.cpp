/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       23.01.2020
 *
 *  Bitwise operations
 */

#include <iostream>
#include <set>
#include <cassert>          // needed for assert macros

using std::cout;
using std::string;

typedef unsigned int UInt;


// Method prints the given number in binary form, separating individual
// octets by ' character.
void printUIntAsBits(UInt num)
{
    static const size_t sz = sizeof(UInt) * 8;  // number of bits
    UInt mask = 0x1 << (sz - 1);

    unsigned char ctr = 0;

    //for(size_t i = 0; i < (sz - 1); ++i)
    while(mask)
    {
        if(ctr == 8)            // разделитель
        {
            cout << '\'';
            ctr = 0;
        }

        if(num & mask)
            cout << 1;
        else
            cout << 0;

        mask >>= 1;
        ++ctr;
    }

    int a = 0;
}


int main()
{
    cout << "Hello world of bits!\n\n";


    UInt a = 1;
    printUIntAsBits(a);
    cout << '\n';

    //printUIntAsBits(0xAACC5577);
    printUIntAsBits(-42);
    cout << '\n';

    // bitwise NOT
    cout << "~0 = ";
    UInt a1 = ~0;           // 11111111'11111111'11111111'11111111
    UInt a2 = 0xAA55AA55;   // 10101010'01010101'10101010'01010101
    printUIntAsBits(a1);
    cout << '\n';

    cout << "OR: ";
    UInt a3 = 0xA5;         // 10100101
    UInt a4 = 0xF0;         // 11110000
    UInt r1 = a3 | a4;      // 11110101
    printUIntAsBits(r1);
    cout << '\n';

    cout << "AND: ";
    UInt a5 = 0xA5;         // 10100101
    UInt a6 = 0xF0;         // 11110000
    UInt r2 = a5 & a6;      // 10100000
    printUIntAsBits(r2);
    cout << '\n';


    cout << "XOR: ";
    UInt a7 = 0xA5;             // 10100101
    UInt a8 = 0xF0;             // 11110000
    UInt r3 = a7 ^ a8;          // 01010101
    UInt r4 = (a7 ^ a8) ^ a8;   // 10100101
    printUIntAsBits(r3);
    cout << '\n';
    printUIntAsBits(r4);
    cout << '\n';


    cout << "<< ";
    UInt a9 = 0x05;         // 00000101
    UInt r5 = a9 << 3;      // 00101000 = 40 (5 * 2^3)
    printUIntAsBits(r5);
    cout << '\n';


    cout << ">> ";
    UInt a10 = 41;          // 00101001
    UInt r6 = a10 >> 4;     // 00000010 = 2
    printUIntAsBits(r6);
    cout << '\n';

    cout << "\n\n";
    return 0;
}
