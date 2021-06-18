#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <list>
#include <vector>
#include "struct.h"
#include <string>



class Vertex;//����� ���  ����� ������� �����
class Edge;//����� ��� ����� ����� 
class Graph;//����� ��� ����� �����


using verticesContainer = vector<Vertex>;
using edgesContainer = vector<Edge>;

class Vertex {//����� ��� ����� ����� 
private:
    Worker data;
public:
    Vertex(Worker& d);
    Worker& getData();
    bool operator== (const Vertex& v)const {
        return this->data == v.data;
    }
};

class Edge {//����� ��� ����� �����
private:
    size_t from;
    size_t to;
    int distance;
public:
    Edge(size_t f, size_t t, int dist);
    int getDistance();
    void setDistance(int distance);
    size_t getFromVertex();
    size_t getToVertex();
};

class GraphFunctionality {
public:
    virtual bool isEdge(size_t u, size_t v) = 0;
    virtual int edgeWeight(size_t u, size_t v) = 0;
    virtual size_t verticesSize() = 0;
    virtual size_t edgesSize() = 0;
    virtual edgesContainer& getEdges() = 0;
    virtual verticesContainer& getVertices() = 0;
    virtual void addSpecialVertex() = 0;
};

class AdjecentListBasedGraph {//����� ��� ����� ������ ���������� ��������
private:
    verticesContainer vertices;
    edgesContainer edges;

    Edge& findEdge(size_t u, size_t v)throw(runtime_error);
public:
    AdjecentListBasedGraph(string file, vector<Worker>& dataVector);
    bool isEdge(size_t u, size_t v);
    int edgeWeight(size_t u, size_t v);
    edgesContainer& getEdges();
    verticesContainer& getVertices();
    size_t verticesSize();
    size_t edgesSize();
    void addSpecialVertex();
};

class Graph : public GraphFunctionality {//����� ��� ����� �����
private:
    AdjecentListBasedGraph graphData;
public:
    Graph(string file, vector<Worker>& dataVector);
    bool isEdge(size_t u, size_t v);
    int edgeWeight(size_t u, size_t v);
    edgesContainer& getEdges();
    verticesContainer& getVertices();
    size_t verticesSize();
    size_t edgesSize();
    void addSpecialVertex();

};

#endif /* graph_h */