#include <iostream>
#include "tree.hpp"
#include "classes.h"

int main() 
{
    std::cout << white;
    auto* persistentSet = new PersistentSet<Department>;
    Department man1 = Department("A");
    Department man2 = Department("B");
    Department man3 = Department("C");
    Department man4 = Department("D");
    Department man5 = Department("E");
    Department man6 = Department("F");
    Department man7 = Department("G");
    Department man8 = Department("H");
    Department man9 = Department("I");
    Department man10 = Department("J");

    Department sorted[10] = { man1, man2, man3, man4, man5, man6, man7, man8, man9, man10 };
    Department ar[10] = { man4, man2, man3, man6, man10, man5, man1, man8, man7, man9 };

    for (int i = 0; i < 10; i++) 
    {
        persistentSet->Insert(ar[i]);
        std::cout << "------------insert---------\n";
    }

    for (int i = 1; i < 10; i++) 
    {
        persistentSet->Remove(sorted[i]);
        std::cout << "------------delete---------\n";
    }

    persistentSet->Print();
}



