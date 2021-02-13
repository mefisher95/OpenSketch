#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <ostream>

class Vertex
{
public:
    Vertex(int x = 0, int y = 0);

    int &x();
    int &y();

    int x() const;
    int y() const;

private:
    int x_;
    int y_;
};


typedef std::vector< Vertex* > Verticies;

std::ostream &operator<<(std::ostream &cout, const Vertex &v);
std::ostream &operator<<(std::ostream &cout, const Verticies &vs);

#endif