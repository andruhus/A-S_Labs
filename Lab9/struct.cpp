

#include "struct.h"





Worker::Worker(string name, int number) {
    this->name = name;
    this->number = number;
    
}

Worker::Worker() :name("no name"), number(0) {}

Worker::Worker(Worker const& p) {
    name = p.name;
    number = p.number;
    
}

bool Worker::operator<(const Worker& p)const {
    return this->name < p.name;
}

bool Worker::operator>(const Worker& p)const {
    return this->name > p.name;
}

bool Worker::operator==(const Worker& p)const {
    return this->name == p.name;
}

bool Worker::operator<=(const Worker& p)const {
    return (this->name < p.name) || (this->name == p.name);
}

bool Worker::operator>=(const Worker& p)const {
    return (this->name > p.name) || (this->name == p.name);
}

ostream& operator<<(ostream& output, Worker p) {
    output << p.name << " (" << p.number << "$ ) ";
    return  output;
}