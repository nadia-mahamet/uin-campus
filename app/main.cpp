#include "uincampus/version.hpp"
#include <iostream>
int main()
{
    std::cout << "UIN-Campus — Système de gestion académique" << std::endl;
    std::cout << "Version " << uin::version() << std::endl;
}
