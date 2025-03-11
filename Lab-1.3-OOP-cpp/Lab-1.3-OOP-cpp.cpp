#include <iostream>
#include "Trapeze.h"

int main()
{
    // Створення трьох трапецій
    Trapeze TR1(1, 2, 3, 4, 5, 6, 7, 8);
    Trapeze TR2(8, 7, 6, 5, 4, 3, 2, 1);
    Trapeze TR3(1, 2, 3, 4, 8, 7, 6, 5);

    std::cout << "Trapeze 1:\n";
    std::cout << TR1 << std::endl;
    std::cout << "Trapeze 2:\n";
    std::cout << TR2 << std::endl;
    std::cout << "Trapeze 3:\n";
    std::cout << TR3 << std::endl;

    // Зменшення трапеції 3 на 3 одиниці 
    Trapeze tSub = TR3 - 3.0;
    std::cout << "After subtracting 3 units from TR3:\n";
    std::cout << tSub << std::endl;

    // Множення двох трапецій
    Trapeze tMul = TR3 * TR2;
    std::cout << "\Product of TR3 * TR2:\n";
    std::cout << tMul << std::endl;

    // Поміщення результату в першу трапецію
    Trapeze tImp = TR1 += tMul;
    std::cout << "Implementation in T1:\n";
    std::cout << tImp << std::endl;

    return 0;
}
