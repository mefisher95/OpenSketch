#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include "Vertex.h"

class Shape
{
public:
    Shape(int x = 0, int y = 0,
          int w = 0, int h = 0,
          const Color& color = BLACK)
    :color_(color), x_(x), y_(y), w_(w), h_(h)
    {}

    Shape(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, 
          int x = 0, int y = 0,
          int w = 0, int h = 0)
    {
        color_ = { r, g, b};
    }

    ~Shape()
    {
        for (int i = 0; i < verticies.size(); ++i)
        {
            delete verticies[i];
        }
    }

    virtual Color get_color () const { return color_; }
    virtual Verticies get_verticies() const { return verticies; }
    virtual Verticies &get_verticies() { return verticies; }

    virtual void move_vertex(Vertex*v, int x, int y) { v->x() = x; v->y() = y; }
    virtual void translate(int dx, int dy)
    {
        for (int i = 0; i < verticies.size(); ++i)
        {
            move_vertex(verticies[i], verticies[i]->x() + dx, 
                        verticies[i]->y() + dy);
        }
    }
    virtual int &x() { return x_; }
    virtual int &y() { return y_; }
    virtual int &w() { return w_; }
    virtual int &h() { return h_; }

    virtual int x() const { return x_; }
    virtual int y() const { return y_; }
    virtual int w() const { return w_; }
    virtual int h() const { return h_; }



protected:
    int x_, y_, w_, h_;
    Color color_;
    Verticies verticies;
};

class Rect: public Shape
{
public:
    Rect(int x = 0, int y = 0, int w = 0, int h = 0, const Color &color = BLACK)
    :Shape(x, y, w, h, color)
    {
        verticies.push_back(new Vertex(x, y));
        verticies.push_back(new Vertex(x + w, y));   
        verticies.push_back(new Vertex(x + w, y + h));   
        verticies.push_back(new Vertex(x, y + h));   
    }
    
};

#endif