

#ifndef JohnsonAlgorithm_h
#define JohnsonAlgorithm_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "graph.h"




using distanceVector = vector<int>;

distanceVector belmanFord(GraphFunctionality& graph, size_t fromVertex) throw(runtime_error);//������� ������ �������� �������-�����

void relax(distanceVector& dist, GraphFunctionality& graph, size_t u, size_t v); //������ ���������� ����� ����� ���������� � �����

void relax(distanceVector& dist, edgesContainer& edgesWeight, size_t u, size_t v); //������ ���������� ����� ����� ���������� � �����

vector<distanceVector> johnsonAlgorithm(GraphFunctionality& g);//������� ������ �������� �������� 

void initDistanceVector(distanceVector& distance, size_t fromVertex);// ������ ����� � �����

pair<size_t, int> findMin(vector<bool>& in, edgesContainer& edgesWeight);//���� �������� �����

distanceVector dijkstra(GraphFunctionality& graph, edgesContainer newEdgesWeight, size_t fromVertex);//������� ����� �������� ��������

void initDistanceVector(distanceVector& distance, size_t fromVertex);

#endif /* JohnsonAlgorithm_h */