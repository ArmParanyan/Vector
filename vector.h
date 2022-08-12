#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

class Vector
{
public:
    Vector();
    Vector(const Vector&);
    Vector(int, int);
    ~Vector();

public:
    void push_back(int);
    void insert(int, int);
    int find_by_value(int);
    void remove_by_value(int);

public:
    Vector& operator=(const Vector&);
    int operator[](int);
    Vector operator+(const Vector&);
    Vector& operator+=(const Vector&);
    friend std::ostream& operator<<(std::ostream&, const Vector&);

private:
    int m_capacity;
    int m_size;
    int* m_vec;
};

#endif //VECTOR_H