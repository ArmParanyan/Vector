#include <iostream>
#include "vector.hpp"

int main() {
    Vector obj;
    obj.push_back(8);
    obj.push_back(5);
    obj.push_back(8);
    obj.push_back(7);
    obj.push_back(8);
    obj.remove_by_value(8);
     
    std::cout << obj << std::endl;
    return 0;
}