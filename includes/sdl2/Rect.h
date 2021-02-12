#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect: public Shape
{
public:
    Rect(const Color &color = BLACK, int x = 0, int y = 0, int w = 0, int h = 0)
    :Shape(color, x, y, w, h)
    {
        verticies.push_back(Vertex(x, y));
        verticies.push_back(Vertex(x + w, y));   
        verticies.push_back(Vertex(x, y + h));   
        verticies.push_back(Vertex(x + w, y + h));   
    }
};

#endif