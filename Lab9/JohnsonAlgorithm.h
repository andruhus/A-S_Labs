

#ifndef JohnsonAlgorithm_h
#define JohnsonAlgorithm_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "graph.h"




using distanceVector = vector<int>;

distanceVector belmanFord(GraphFunctionality& graph, size_t fromVertex) throw(runtime_error);//функція виконує алгоритм Белмана-Форда

void relax(distanceVector& dist, GraphFunctionality& graph, size_t u, size_t v); //робить релаксацію ребра тобто виключення з циклу

void relax(distanceVector& dist, edgesContainer& edgesWeight, size_t u, size_t v); //робить релаксацію ребра тобто виключення з циклу

vector<distanceVector> johnsonAlgorithm(GraphFunctionality& g);//функція виконує алгоритм Джонсона 

void initDistanceVector(distanceVector& distance, size_t fromVertex);// вилучає ребро з циклу

pair<size_t, int> findMin(vector<bool>& in, edgesContainer& edgesWeight);//щукає мінімальне ребро

distanceVector dijkstra(GraphFunctionality& graph, edgesContainer newEdgesWeight, size_t fromVertex);//функція викнує алгоритм Дейкстри

void initDistanceVector(distanceVector& distance, size_t fromVertex);

#endif /* JohnsonAlgorithm_h */