#include <iostream>
using namespace std;

int main()
{
    unsigned int color = 0x123456;

    unsigned int red = (color & 0xFF0000) >> 16;
    unsigned int green = (color & 0x00FF00) >> 8;
    unsigned int blue = (color & 0x0000FF);

    cout << hex << red << endl;
    cout << hex << green << endl;
    cout << hex << blue << endl;
    cout << endl;

    // OR


    // UNSIGNED CHAR ONLY HOLDS 1 BYTE, SO SHIFTING DISCARDS THE REST
    unsigned char red2 = color >> 16;
    unsigned char green2 = color >> 8;

    // FIRST BYTE OF COLOR IS ASSGNED TO BLUE
    unsigned char blue2 = color;

    cout << hex << (int)red2 << endl;
    cout << hex << (int)green2 << endl;
    cout << hex << (int)blue2 << endl;

    return 0;

}   