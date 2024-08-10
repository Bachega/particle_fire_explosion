#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char ** argv)
{
    // 0xFF123456

    unsigned char alpha = 0xff;
    unsigned char red = 0x12;
    unsigned char green = 0x56;
    unsigned char blue = 0x34;

    unsigned int color = 0;
    
    color += alpha;

    cout << setfill('0') << setw(8) << hex << color << endl;

    color <<= 8; // 8 bits -> 1 byte
    
    color += red;

    cout << setfill('0') << setw(8) << hex << color << endl;

    color <<= 8;

    color += green;

    cout << setfill('0') << setw(8) << hex << color << endl;

    color <<= 8;

    color += blue;

    cout << setfill('0') << setw(8) << hex << color << endl;

    return 0;
}