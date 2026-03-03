#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base &p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Base reference is type: A" << std::endl;
        return ;
    } 
    catch (...) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Base reference is type: B" << std::endl;
        return ;
    }
    catch (...) {}
    try 
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Base reference is type: C" << std::endl;
        return ;
    } 
    catch (...) {}
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Base pointer is type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Base pointer is type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Base pointer is type: C" << std::endl;
}

Base *generate()
{
    srand(time(NULL));
    int n1 = rand() % 6 + 1;
    int n2 = rand() % 6 + 1;
    int n = n1 + n2 / 2;

    if (n == 1 || n == 3)
        return (new A());
    else if (n == 6 || n == 4)
        return (new B());
    else
        return (new C());
}

int main()
{
    Base *check = generate();
    identify(check);
    identify(check);
    delete(check);
    return (0);
}