#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "vector.h"
 
//default constructor
Vector::Vector() {
    m_capacity = 1;
    m_size = 0;
    m_vec = new int[m_capacity];
}

// copy constructor
Vector::Vector(const Vector& oth) {
    m_capacity = oth.m_capacity;
    m_size = oth.m_size;
    if (0 == m_size) {
        m_vec = new int[m_capacity];
        for (int i = 0; i < m_capacity; ++i) {
            m_vec[i] = oth.m_vec[i];
        }
    } else {
        for (int i = 0; i < m_size; ++i) {
            m_vec[i] = oth.m_vec[i];
        }
    }
}

//parametrized constructor
Vector::Vector(int count, int value) {
    if (count > 0) {
        m_size = count;
        m_capacity = count;
        m_vec = new int[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_vec[i] = value;
        }
    } else {
        std::cout << "count can't be negative or zero" << std::endl;
    }
}

//destructor constructor
Vector::~Vector() {
    delete[] m_vec;
    m_vec = nullptr;
}

//push back
void Vector::push_back(int value) {
    int* tmp = new int[m_capacity];
     if (m_capacity == m_size) {
        m_capacity *= 2;
        int* new_vector = new int[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            new_vector[i] = m_vec[i];
        }

        delete[] m_vec;
        m_vec = nullptr;
        m_vec = new_vector;
        new_vector = nullptr;  
    }
    
    m_vec[m_size] = value;
    ++m_size;
}

//insert
void Vector::insert(int index, int value) {
    if (index > m_size || index < 0) {
        std::cout << "index can't be greater of size and can't be negative" << std::endl;
        return;
    }
    if (index == m_size) {
        push_back(value);
        return;
    }
    if (m_capacity == m_size) {
        m_capacity *= 2;
    }
    
    int* tmp = new int[m_size + 1];
    for (int i = 0, j = 0; i < m_size; ++i, ++j) {
        if (i == index) {
            tmp[j] = value;
            ++j;
        }
        tmp[j] = m_vec[i];
        }
    delete[] m_vec;
    m_vec = tmp;
    ++m_size;
}

int Vector::find_by_value(int value) {
    if (0 == m_size) {
        std::cout << "vector is empty:" << std::endl;
        return 0;
    }
    for (int i = 0; i < m_size; ++i) {
        if (m_vec[i] == value) {
            return i;
        } 
    }
    return -1;
}

void Vector::remove_by_value(int value) {
    if (0 == m_size) {
        std::cout << "vector is empty:" << std::endl;
        return;
    }
    int count = 0;
    
        int* tmp = new int [m_capacity];
        for (int i = 0, j = 0; i < m_size; ++i, ++j) {
            if (m_vec[i] == value) {
                ++count;
                ++j;
            }
                tmp[i] = m_vec[j];
            }
        
        delete[] m_vec;
        m_vec = tmp;
    
    m_size = m_size - count;

}

//operator =
Vector& Vector::operator=(const Vector& oth) {
    m_size = oth.m_size;
    m_capacity = oth.m_capacity;
    delete[] m_vec;
    m_vec = new int[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i] = oth.m_vec[i];
    }
    return *this;
}

//operator +
Vector Vector::operator+(const Vector& oth) {
   Vector tmp;
   tmp.m_capacity = m_capacity > oth.m_capacity ? m_capacity : oth.m_capacity;
   tmp.m_size = m_size > oth.m_size ? m_size : oth.m_size;

    for (int i = 0; i < tmp.m_size; ++i) {
        if (i >= m_capacity) {
            tmp.m_vec[i] = oth.m_vec[i] + 0;
        } else if (i >= oth.m_capacity) {
            tmp.m_vec[i] = m_vec[i] + 0;
        } else {
            tmp.m_vec[i] = m_vec[i] + oth.m_vec[i];
        }
    }
    return tmp;
} 

Vector& Vector::operator+=(const Vector& oth) {
    Vector tmp;
   tmp.m_capacity = m_capacity > oth.m_capacity ? m_capacity : oth.m_capacity;
   tmp.m_size = m_size > oth.m_size ? m_size : oth.m_size;

    for (int i = 0; i < tmp.m_size; ++i) {
        if (i >= m_capacity) {
            tmp.m_vec[i] = oth.m_vec[i] + 0;
        } else if (i >= oth.m_capacity) {
            tmp.m_vec[i] = m_vec[i] + 0;
        } else {
            tmp.m_vec[i] = m_vec[i] + oth.m_vec[i];
        }
    }

    m_capacity = tmp.m_capacity;
    m_size = tmp.m_size;
    delete[] m_vec;
    m_vec = new int [m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i] = tmp.m_vec[i];
    }
    return *this;
}

//operator []
int Vector::operator[](int index) {
    if (index > m_size || index < 0) {
        std::cout << "index can't be greater of size and can't be negative" << std::endl;
    }
    return m_vec[index];
}

//operator <<
std::ostream& operator<<(std::ostream& out, const Vector& oth) {
    for (int i = 0; i < oth.m_size; ++i) {
        out << oth.m_vec[i] << " ";
    }
    return out;
}
#endif //VECTOR_HPP