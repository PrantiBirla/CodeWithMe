#include <iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
bool isBipartite(vector<int>* edges, int n) {
    if (n == 0)
        return true;
    unordered_set<int> sets[2];//for storing vertices and their neighbours 
    //if two are vertices then they cannot be same set, if we can arrange vertices in such a manner that graph is bipartite
    queue<int> pendingvertices;// for storing pending vertices;
    pendingvertices.push(0);
    sets[0].insert(0);
    while (!pendingvertices.empty()) {
        int currVertex = pendingvertices.front();
        pendingvertices.pop();
        int currSet = sets[0].count(currVertex) > 0 ? 0 : 1;
        //checking neighbours of current vertex 
        for (int i = 0; i < edges[currVertex].size(); i++) {
            int neighbour = edges[currVertex][i];
            if (sets[0].count(neighbour) == 0 && sets[1].count(neighbour) == 0) {//if neighbour is not present in any set
                sets[1 - currSet].insert(neighbour);
                pendingvertices.push(neighbour);
            }
            else if (sets[currSet].count(neighbour) != 0)//if neighbour is present in same set then graph is not bipartite
                return false;
        }
    }
    return true;
}
int main()
{
    int n, e;//no of vertices and no of edges
    cin >> n >> e;
    vector<int>* edges = new vector<int>[n];//for storing edges
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    bool ans = isBipartite(edges, n);
    if (ans)
        cout << "Bipartite" << endl;
    else
        cout << "Not Bipartie" << endl;
}

