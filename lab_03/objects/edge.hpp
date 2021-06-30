#ifndef EDGE_HPP
#define EDGE_HPP


class Edge
{
public:
    Edge();
    Edge(const int point1, const int point2);
    ~Edge() = default;

    int get_first();
    void set_first(int index);

    int get_second();
    void set_second(int index);

private:
    int point1;
    int point2;
};


#endif
