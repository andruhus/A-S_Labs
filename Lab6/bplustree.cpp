#include <iostream>
#include <vector>
#include <string>
#include "b_plus_tree_structure.hpp"
#include "classes.h"

using namespace std;

//Testing function
void Example() {


    vector<Department> mans;
    int n = 10;

    BPlusTree<Department> tree(3);
    for (int i = 0; i < n;i++) {
        Department man(to_string(i));
        tree.Insert(man);
    }
    tree.Print();
    system("pause");
    Department man(to_string(8));
    tree.Remove(man);
    tree.Print();
}
int main()
{
    Example();
    return 0;
}


