#include "Color.h"

Color rand_color()
{
    return Color { Uint8(rand() % 256), Uint8(rand() % 256), 
                   Uint8(rand() % 256), Uint8(255)};
}