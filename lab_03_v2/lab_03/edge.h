#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge();
    Edge(const long point1, const long point2);
    ~Edge() = default;

    long get_first();
    void set_first(long index);

    long get_second();
    void set_second(long index);

private:
    long point1;
    long point2;
};

#endif // EDGE_H
