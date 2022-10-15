#include <iostream>
#include<stack>
#include<vector>
using namespace std;
//this function travel throgh vertices ans we store the vertices in a stack as per their finishing time
void dfs(int** edges, int n, int sv,stack<int>* s, bool* visited) {
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (edges[sv][i] == 1 && !visited[i]) {
			dfs(edges, n, i, s, visited);
		}
	}
	s->push(sv);
}
// this function travels through vertices and edges are placed transpose of another ans starting vertex is top element of stack
//i.e(which enters at last during dfs fun) this is because as this will help to print every component otherwise some component can be missed.
void reverseDFS(int** edges, int n, int sv, bool* visited,vector<int>* component) {
	visited[sv] = true;
	component->push_back(sv);
	for (int i = 0; i < n; i++) {
		if (edges[sv][i] == 1 && !visited[i]) {
			reverseDFS(edges, n, i, visited,component);
		}
	}
}
int main()
{
	int n,e;//no of vertices,no of edges
	cin >> n>>e;
	int** edges = new int* [n];//for storing edges
	for (int i = 0; i < n; i++)
		edges[i] = new int[n]();
	int** transpose = new int* [n];
	for (int i = 0; i < n; i++) 
		transpose[i] = new int[n];
	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges[v1][v2]=1;//graph is directed
		transpose[v2][v1] = 1;
	}
	stack<int>* s = new stack<int>;//for storing vertices as per their finishing time
	bool* visited = new bool[n]();
	for (int i = 0; i < n; i++)
	{
		if(!visited[i])
			dfs(edges, n, i, s, visited);
	}
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	cout << endl;
	while (!s->empty()) {
		if (!visited[s->top()]) {
			vector<int>* component = new vector<int>;
			reverseDFS(transpose, n, s->top(), visited,component);
			for (int i = 0; i < component->size(); i++)
				cout << component->at(i) << " ";
			cout << endl;
			delete component;
		}
		s->pop();
	}
	for (int i = 0; i < n; i++) {
		delete[]transpose[i];
		delete[]edges[i];
	}
	delete[]transpose;
	delete[]edges;
	delete[]visited;
	delete s;
}
