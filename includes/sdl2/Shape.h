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
        color_ = { r, g, b, 255};
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
    virtual void resize(int w, int h) = 0;

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

class Point: public Shape
{
    Point(int x, int y, const Color &c = BLACK)
    :Shape(x, y, 0, 0, c)
    {
        verticies.push_back(new Vertex(x, y));
    }

    void resize(int w, int h) { return; }

};

class Line: public Shape
{
public:
    Line(int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0,
         const Color &color = BLACK)
    :Shape(x0, y0, x1, y1, color)
    {
        verticies.push_back(new Vertex(x0, y0));
        verticies.push_back(new Vertex(x1, y1));
    }

    void resize(int h, int w) { return; }
};

class Triangle: public Shape
{
public:
    Triangle(int x = 0, int y = 0, 
             int w = 0, int h = 0, 
             const Color &color = BLACK)
    :Shape(x, y, w, h, color)
    {
        verticies.push_back(new Vertex((x + w / 2), y));
        verticies.push_back(new Vertex(x, y + h));   
        verticies.push_back(new Vertex(x + w, y + h));   
    }

    void resize(int h, int w)
    {
        verticies[0]->x() = x_ + w / 2;
        verticies[1]->y() = y_ + h;
        verticies[2]->x() = x_ + w;
        verticies[2]->y() = y_ + h;
    }
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

        void resize(int h, int w)
    {
        verticies[1]->x() = x_ + w;
        verticies[2]->x() = x_ + w;
        verticies[2]->y() = y_ + h;
        verticies[3]->y() = y_ + h;
    }
    
};

#endif