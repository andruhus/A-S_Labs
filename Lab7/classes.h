#pragma once
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <conio.h>

//Class for description of worker 
class Worker
{
private:
    std::string name_;

public:
    //Constructors
    Worker();
    Worker(const std::string& name);
    //Method that return name of worker
    std::string GetName() const;
};

class Department
{
private:
    std::string name_;
    std::vector<Worker> workers_;
public:
    //Constructors
    Department();
    Department(const std::string& name);
    Department(const std::vector<Worker>& workers);
    Department(const std::string& name, const std::vector<Worker>& workers);

    //Method for setting list of workers
    void SetWorkers(const std::vector<Worker>& workers);

    //Method for adding new worker
    void AddWorkers(const Worker& worker);

    //Method for adding list of workers
    void AddWorkers(const std::vector<Worker>& workers);

    //Method for getting name of department
    std::string GetName() const;

    //Method for getting list of workers
    std::vector<Worker> GetWorkers() const;
};

//overloads of operator for output different classes
std::ostream& operator<<(std::ostream& os, const Worker& worker);
std::ostream& operator<< (std::ostream& os, const Department& m);

template<class K, class V>
std::ostream& operator<<(std::ostream& os, const std::pair<K, V> p)
{
    os << "([" << p.first << "]: " << p.second << ")\n";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "{";
    bool first = true;
    for (auto it = v.begin(); it != v.end(); it++)
    {

        if (!first)
            os << ", ";
        first = false;
        os << *it;
    }
    os << "}";
    return os;
}

//overloads comparison operators for Workers
bool operator>(const Worker& m1, const Worker& m2);
bool operator<(const Worker& m1, const Worker& m2);
bool operator>=(const Worker& m1, const Worker& m2);
bool operator<=(const Worker& m1, const Worker& m2);
bool operator==(const Worker& m1, const Worker& m2);
bool operator!=(const Worker& m1, const Worker& m2);

//overloads comparison operators for Departments
bool operator>(const Department& m1, const Department& m2);
bool operator<(const Department& m1, const Department& m2);
bool operator>=(const Department& m1, const Department& m2);
bool operator<=(const Department& m1, const Department& m2);
bool operator==(const Department& m1, const Department& m2);
bool operator!=(const Department& m1, const Department& m2);

//Function for parsing line into different workers
std::vector<Worker> Parse(const std::string& s);