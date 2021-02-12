#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>
#include "Color.h"


class Vertex
{
public:
    Vertex(int x = 0, int y = 0)
    :x_(x), y_(y)
    {}

    int &x() { return x_; }
    int &y() { return y_; }

    int x() const { return x_; }
    int y() const { return y_; }

private:
    int x_;
    int y_;
};

typedef std::vector< Vertex > Verticies;


std::ostream &operator<<(std::ostream &cout, const Vertex &v)
{
    cout << "(" << v.x() <<  ", " << v.y() << ")";
    return cout;
}
std::ostream &operator<<(std::ostream &cout, const Verticies &vs)
{
    cout << "{ ";
    for (int i = 0; i < vs.size(); ++i)
    {
        cout << vs[i];
        if (i < vs.size() - 1) cout << ", ";
    }
    cout << " }";
    return cout;
}


class Shape
{
public:
    Shape(const Color& color = BLACK, 
          int x = 0, int y = 0,
          int w = 0, int h = 0)
    :color_(color), x_(x), y_(y), w_(w), h_(h)
    {}

    Shape(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, 
          int x = 0, int y = 0,
          int w = 0, int h = 0)
    {
        color_ = { r, g, b};
    }

    virtual Color get_color () const { return color_; }
    virtual Verticies get_verticies() const { return verticies; }

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




#endif