#include "Serializer.hpp"

int main()
{
    Data    d("hola");
    Data    *ptr = &d;
    Serializer  s;
    std::cout << ptr << std::endl;
    uintptr_t i = s.serialize(ptr);
    ptr = s.deserialize(i);
    std::cout << ptr << std::endl;
    return 0;
}