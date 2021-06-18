
#include <iostream>
#include "JohnsonAlgorithm.h"
#include "graph.h"
#include "struct.h"
using namespace std;




int main() {//функція мейн у ній все тестуються 

	vector<Worker> staff = { {"A",300},{"B",450},{"C",340},{"D",450} };
	Graph g("WGraph2.txt",staff);

	auto v = johnsonAlgorithm(g);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++)
			cout << " " << v[i][j] << " ";
		cout << endl;
	}

}


