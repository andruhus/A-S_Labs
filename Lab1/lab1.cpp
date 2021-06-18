#include <iostream>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int WORKER_ID = 1;
int GROUP_ID = 1;

//Class for description worker
class Worker
{
private:
    string name_;

public:
    //Constructors
    Worker() : name_("New worker " + to_string(WORKER_ID++)) {};

    Worker(const string& name) : name_(name) { WORKER_ID++; };

    //Method that return name of worker
    string GetName() const
    {
        return name_;
    }
};

//Class for description different departments
class Department
{
private:
    string name_;
    vector<Worker> workers_;
public:
    //Constructors
    Department() : name_("NULL") {};
    Department(const string& name) : name_(name) { GROUP_ID++; };
    Department(const vector<Worker>& workers) : name_("New department " + to_string(GROUP_ID++)), workers_(workers) {};
    Department(const string& name, const vector<Worker>& workers) : name_(name), workers_(workers) { GROUP_ID++; };

    //Method for setting list of workers
    void SetWorkers(const vector<Worker>& workers)
    {
        this->workers_ = workers;
    }

    //Method for adding new workers
    void AddWorkers(const Worker& worker)
    {
        workers_.insert(workers_.end(), worker);
    }

    //Method for adding list of workers
    void AddWorkers(const vector<Worker>& workers)
    {
        workers_.insert(workers_.end(), workers.begin(), workers.end());
    }

    //Method for getting name of department
    string GetName() const
    {
        return name_;
    }

    //Method for getting list of workers
    vector<Worker> GetWorkers() const
    {
        return workers_;
    }
};

//Structure for description parameters of hashing
struct Params
{
    int m;
    int a;
    int b;
    int p;
};

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

template<class K, class V>
ostream& operator<<(ostream& os, const pair<K, V> p)
{
    os << "([" << p.first << "]: " << p.second << ")\n";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
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

ostream& operator<< (ostream& os, const Department& m)
{
    os << "Department: " << m.GetName() << "(" << m.GetWorkers() << ")";
    return os;
}

//Function for finding next simple number
int NextSimple(int number)
{
    number++;
    if (number == 1 || number == 2)
        return number;
    if (number % 2 == 0)
        return NextSimple(number);
    for (int i = 3; i * i <= number; i += 2)
        if (number % i == 0)
            return NextSimple(number);
    return number;
}

//Function for hashing strings
int Hash(const string& t)
{
    int res = 0;
    for (int i = 0; i < static_cast<int>(t.size()); i++)
        res += i * t[i];
    return res;
}

//Function for hashing department
int HashGroup(const Department& m)
{
    int res = 0;
    res += Hash(m.GetName());
    for (auto i : m.GetWorkers())
    {
        res += Hash(i.GetName());
    }
    return res;
}

//Function that returns hash-table
pair<Params, vector<pair<Params, vector<Department>>>> IdealHash(const vector<Department>& v)
{
    int p = NextSimple(HashGroup(*v.rbegin()));
    int m = static_cast<int>(v.size());
    vector<pair<Params, vector<Department>>> res(m);
    int a = rand() % p;
    int b = rand() % p;
    for (auto i : v)
    {
        int h = ((a * HashGroup(i) + b) % p) % m;
        res[h].second.push_back(i);
    }
    Params p1;
    p1.p = p;
    p1.a = a;
    p1.b = b;
    p1.m = m;
    for (size_t i = 0; i < res.size(); i++)
    {
        if (res[i].second.size() > 1)
        {
            int m2 = static_cast<int>(res[i].second.size());
            m2 = m2 * m2;
            while (true)
            {
                bool cont = true;
                set<int> diff;
                vector<Department> temp(m2);
                Params p2;
                p2.p = p;
                p2.m = m2;
                p2.a = rand() % p;
                p2.b = rand() % p;
                for (auto j : res[i].second)
                {
                    int h = ((p2.a * HashGroup(j) + p2.b) % p) % m2;
                    auto in = diff.insert(h);
                    temp[h] = j;
                    cont = cont && in.second;
                }
                if (cont)
                {
                    res[i] = make_pair(p2, temp);
                    break;
                }
                else continue;
            }
        }
        else
        {
            res[i].first.m = static_cast<int>(res[i].second.size());
        }
    }
    return make_pair(p1, res);
}

pair<Params, vector<pair<Params, vector<int>>>> IdealHash(const vector<int>& v)
{
    int p = NextSimple(*v.rbegin());
    int m = static_cast<int>(v.size());
    vector<pair<Params, vector<int>>> res(m);
    int a = rand() % p;
    int b = rand() % p;
    for (auto i : v)
    {
        int h = ((a * i + b) % p) % m;
        res[h].second.push_back(i);
    }
    Params p1;
    p1.p = p;
    p1.a = a;
    p1.b = b;
    p1.m = m;
    for (size_t i = 0; i < res.size(); i++)
    {
        if (res[i].second.size() > 1)
        {
            int m2 = static_cast<int>(res[i].second.size());
            m2 = m2 * m2;
            while (true)
            {
                bool cont = true;
                set<int> diff;
                vector<int> temp(m2);
                Params p2;
                p2.p = p;
                p2.m = m2;
                p2.a = rand() % p;
                p2.b = rand() % p;
                for (auto j : res[i].second)
                {
                    int h = ((p2.a * j + p2.b) % p) % m2;
                    auto in = diff.insert(h);
                    temp[h] = j;
                    cont = cont && in.second;
                }
                if (cont)
                {
                    res[i] = make_pair(p2, temp);
                    break;
                }
                else continue;
            }
        }
        else
        {
            res[i].first.m = static_cast<int>(res[i].second.size());
        }
    }
    return make_pair(p1, res);
}

int main()
{
    Department d1("department1");
    Department d2("department2");
    Department d3("department3");
    Department d4("department4");
    Department d5("department5");
    Department d6("department6");
    Department d7("department7");
    cout << IdealHash({ d1,d2,d3,d4,d5,d6,d7}) << endl;
    cout << endl << endl;
    cout << IdealHash({ 10,15,23,46,57,83 }) << endl;
    return 0;
}