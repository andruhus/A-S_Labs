#include "Heap.hpp"
#include "classes.h"

int main() 
{
    Department man1("a");
    Department man2("b");
    Department man3("c");
    Department man4("d");
    Department man5("e");
    Department man6("f");
    Department man7("g");
    Department man8("h");
    Department man9("i");
    Department man10("j");
    FibonacciHeap<Department> heap;
    Node<Department>* temp, * node1 = nullptr;
    std::cout << "INSERT 10 NODES\n\n";
    temp = heap.Insert(man1);
    temp = heap.Insert(man2);
    temp = heap.Insert(man3);
    temp = heap.Insert(man4);
    temp = heap.Insert(man5);
    node1 = temp;
    temp = heap.Insert(man6);
    temp = heap.Insert(man7);
    temp = heap.Insert(man8);
    temp = heap.Insert(man9);
    temp = heap.Insert(man10);

    heap.Print();

    std::cout << "\n\nEXTRACT MIN\n\n";
    heap.ExtractMin();
    heap.Print();

    std::cout << "\n\nDECREASE e to a\n\n";
    heap.DecreaseKey(node1, man1);
    heap.Print();

    std::cout << "\n\nEXTRACT MIN\n\n";
    heap.ExtractMin();
    heap.Print();

    return 0;
}

