#include "Vertex.h"

Vertex::Vertex(int x, int y)
:x_(x), y_(y) {}

int& Vertex::x() { return x_; }
int& Vertex::y() { return y_; }

int Vertex::x() const { return x_; }
int Vertex::y() const { return y_; }

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