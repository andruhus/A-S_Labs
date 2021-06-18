#include "classes.h"

using namespace std;

int WORKER_ID = 1;
int DEPARTMENT_ID = 1;

Worker::Worker() : name_("New worker " + to_string(WORKER_ID++)) {};
Worker::Worker(const string& name) : name_(name) { WORKER_ID++; };

string Worker::GetName() const
{
    return name_;
}

//Constructors
Department::Department() : name_("NULL") {};
Department::Department(const string& name) : name_(name) { DEPARTMENT_ID++; };
Department::Department(const vector<Worker>& workers) : name_("New department " + to_string(DEPARTMENT_ID++)), workers_(workers) {};
Department::Department(const string& name, const vector<Worker>& workers) : name_(name), workers_(workers) { DEPARTMENT_ID++; };

//Method for setting list of workers
void Department::SetWorkers(const vector<Worker>& workers)
{
    this->workers_ = workers;
}

//Method for adding new worker
void Department::AddWorkers(const Worker& worker)
{
    workers_.insert(workers_.end(), worker);
}

//Method for adding list of workers
void Department::AddWorkers(const vector<Worker>& workers)
{
    workers_.insert(workers_.end(), workers.begin(), workers.end());
}

//Method for getting name of department
string Department::GetName() const
{
    return name_;
}

//Method for getting list of workers
vector<Worker> Department::GetWorkers() const
{
    return workers_;
}

//overloads of operator for output different classes
ostream& operator<<(ostream& os, const Params& p)
{
    os << "p: " << p.p << ", m: " << p.m << ", a: " << p.a << ", b: " << p.b;
    return os;
}

ostream& operator<<(ostream& os, const Worker& worker)
{
    os << "Worker: " << worker.GetName();
    return os;
}

ostream& operator<< (ostream& os, const Department& m)
{
    os << "Department: " << m.GetName() << "(" << m.GetWorkers() << ")";
    return os;
}

//overloads comparison operators for Workers
bool operator>(const Worker& m1, const Worker& m2)
{
    return m1.GetName() > m2.GetName();
}

bool operator<(const Worker& m1, const Worker& m2)
{
    return m1.GetName() < m2.GetName();
}

bool operator>=(const Worker& m1, const Worker& m2)
{
    return m1.GetName() >= m2.GetName();
}

bool operator<=(const Worker& m1, const Worker& m2)
{
    return m1.GetName() <= m2.GetName();
}

bool operator==(const Worker& m1, const Worker& m2)
{
    return m1.GetName() == m2.GetName();
}

bool operator!=(const Worker& m1, const Worker& m2)
{
    return m1.GetName() != m2.GetName();
}

//overloads comparison operators for Manufactorers
bool operator>(const Department& m1, const Department& m2)
{
    return m1.GetName() > m2.GetName();
}

bool operator<(const Department& m1, const Department& m2)
{
    return m1.GetName() < m2.GetName();
}

bool operator>=(const Department& m1, const Department& m2)
{
    return m1.GetName() >= m2.GetName();
}

bool operator<=(const Department& m1, const Department& m2)
{
    return m1.GetName() <= m2.GetName();
}

bool operator==(const Department& m1, const Department& m2)
{
    return m1.GetName() == m2.GetName();
}

bool operator!=(const Department& m1, const Department& m2)
{
    return m1.GetName() != m2.GetName();
}


//Function for parsing line into different workers
vector<Worker> Parse(const string& s)
{
    vector<Worker> res;
    stringstream s1(s);
    string word;
    while (getline(s1, word))
    {
        res.push_back(Worker(word));
    }
    return res;
}