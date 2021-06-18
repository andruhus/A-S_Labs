#ifndef struct_h
#define struct_h

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;



class  Worker {//����� ��� ������ ������
public:
    string    name;
    int    number;
   
public:
    Worker(string name, int number);
    Worker(Worker const& model);
    Worker();
    bool operator< (const Worker& p)const;
    bool operator> (const Worker& p)const;
    bool operator== (const Worker& p)const;

    bool operator<= (const Worker& p)const;
    bool operator>= (const Worker& p)const;

    friend ostream& operator<<(ostream& output, Worker p);

};




#endif /* struct_h */