#ifndef COLOR_H
#define COLOR_H

#include <ostream>
#include <SDL2/SDL.h>

typedef SDL_Color Color;

const Color RED    = { 255,   0,   0, 255};
const Color GREEN  = {   0, 255,   0, 255 };
const Color BLUE   = {   0,   0, 255, 255 };
const Color ORANGE = { 255, 165,   0, 255 };
const Color YELLOW = { 255, 255,   0, 255 };
const Color INDIGO = {  75,   0, 130, 255 };
const Color VIOLET = { 238, 130, 238, 255 };

const Color BLACK  = {   0,   0,   0, 255 };
const Color WHITE  = { 255, 255, 255, 255 };
const Color GRAY   = { 100, 100, 100, 255 };

Color rand_color();

// std::ostream &operator<<(std::ostream &cout, const Color &c)
// {
//     cout << "{ Color: " << int(c.r)
//          << ", " << int(c.g)
//          << ", " << int(c.b)
//          << " }";
//     return cout;
// }


#endif
