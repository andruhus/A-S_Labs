#include <iostream>
#include "heap.hpp"
#include "classes.h"

int main() 
{
    Department man1("A");
    Department man2("B");
    Department man3("C");
    Department man4("D");
    Department man5("E");
    Department man6("F");
    Department man7("G");
    Department man8("H");
    Department man9("I");
    Department man10("J");
    BinominalHeap<Department> tree;
    
    tree.Insert(man7);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man8);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man9);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man10);
    std::cout << "NEW TREE\n";
    tree.Print();
    tree.Insert(man1);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man2);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man3);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man4);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man5);
    tree.Print();
    std::cout << std::endl;
    tree.Insert(man6);
    tree.Print();
    std::cout << std::endl;

    std::cout << "EXTRACT MIN\n";
    tree.ExtractMin();
    tree.Print();
    return 0;
}


