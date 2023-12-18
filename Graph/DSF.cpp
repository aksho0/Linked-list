#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

/*
    DFS : Depth First Search
*/

class graph {
public: 

    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction) {

        adj[u].push_back(v);

        if(direction == 0) {
            adj[v].push_back(u);
        }
    }

    void print() {

        for(auto i : adj) {
            cout << i.first << "-> ";
            for(auto j : i.second) {
                cout << j << " ";
            } cout << endl;
        }
    }

};

void DFS(int node, unordered_map<int, list<int> > adj, unordered_map<int, bool> &visited, vector<int> &ans) {

    visited[node] = 1;
    ans.push_back(node);

    for(auto i : adj[node]) {
        if(!visited[i])
            DFS(i, adj, visited, ans);
    }

}

int main() {

    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    graph g;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        //creating an undirected graph
        g.addEdge(u, v, 0);
    }

    /*
    0 1
    0 4
    1 3
    4 3
    2 3
    1 2
    */

    g.print();

    vector<int> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<m; i++) {
        if(!visited[i])
            DFS(i, g.adj, visited, ans);
    }

    
    cout << "DSF Traversal -" << endl;
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}