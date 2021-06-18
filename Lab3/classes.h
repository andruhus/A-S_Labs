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

const std::string red = "\u001B[31m";
const std::string blue = "\u001B[34m";

//Class for description worker
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

//Overloads comparison operators for workers
bool operator>(const Worker& lhs, const Worker& rhs);
bool operator<(const Worker& lhs, const Worker& rhs);
bool operator>=(const Worker& lhs, const Worker& rhs);
bool operator<=(const Worker& lhs, const Worker& rhs);
bool operator==(const Worker& lhs, const Worker& rhs);
bool operator!=(const Worker& lhs, const Worker& rhs);

//Overloads comparison operators for departments
bool operator>(const Department& lhs, const Department& rhs);
bool operator<(const Department& lhs, const Department& rhs);
bool operator>=(const Department& lhs, const Department& rhs);
bool operator<=(const Department& lhs, const Department& rhs);
bool operator==(const Department& lhs, const Department& rhs);
bool operator!=(const Department& lhs, const Department& rhs);

//Function for interactive finding elements
template <class TypeClass>
TypeClass* ChooseNode(TypeClass* current_node)
{
    int position = 0;
    bool end = false;

    while (!end)
    {
        system("cls");
        std::cout << "Parent Node: ";
        if (current_node->parent_)
        {
            if (current_node->parent_->colour_)
                std::cout << red << current_node->parent_->value_ << blue;
            else std::cout << current_node->parent_->value_;
        }
        std::cout << std::endl;
        if (position == 0)
            std::cout << "-> Current Node: ";
        else std::cout << "   Current Node: ";
        current_node->Print(std::cout);
        std::cout << std::endl;
        if (position == 1)
        {
            if (current_node->left_)
                if (current_node->left_->colour_)
                    std::cout << red << "-> Left Node " << current_node->left_->value_ << std::endl << blue;
                else std::cout << "-> Left Node " << current_node->left_->value_ << std::endl;
            else
                std::cout << "-> NULL" << std::endl;
        }
        else
        {
            if (current_node->left_)
                if (current_node->left_->colour_)
                    std::cout << red << "   Left Node " << current_node->left_->value_ << std::endl << blue;
                else std::cout << "   Left Node " << current_node->left_->value_ << std::endl;
            else
                std::cout << "   NULL" << std::endl;
        }
        if (position == 2)
        {
            if (current_node->right_)
                if (current_node->right_->colour_)
                    std::cout << red << "-> Right Node " << current_node->right_->value_ << std::endl << blue;
                else std::cout << "-> Right Node " << current_node->right_->value_ << std::endl;
            else
                std::cout << "-> NULL" << std::endl;
        }
        else
        {
            if (current_node->right_)
                if (current_node->right_->colour_)
                    std::cout << red << "   Right Node " << current_node->right_->value_ << std::endl << blue;
                else std::cout << "   Right Node " << current_node->right_->value_ << std::endl;
            else
                std::cout << "   NULL" << std::endl;
        }
        if (position == 3)
            std::cout << "-> Back;" << std::endl;
        else std::cout << "   Back;" << std::endl;

        char key;
        key = _getch();
        if ((int)key != 13)
        {
            if ((int)key == -32)
            {
                key = _getch();
                if ((int)key == 72)
                {
                    if (position > 0)
                        position--;
                    else position = 3;
                }

                if ((int)key == 80)
                {
                    if (position < 3)
                        position++;
                    else position = 0;
                }
            }
        }
        else
        {
            switch (position)
            {
            case 0:
                return current_node;
            case 1:
                if (current_node->left_)
                    return ChooseNode(current_node->left_);
                break;
            case 2:
                if (current_node->right_)
                    return ChooseNode(current_node->right_);
                break;
            default:
                if (current_node->parent_)
                    return ChooseNode(current_node->parent_);
                break;
            }

        }
    }
}

//Function for parsing line into different workers
std::vector<Worker> Parse(const std::string& s);