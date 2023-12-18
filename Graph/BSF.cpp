#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
/* 
    BSF = Breath first search
*/

class graph {
public:

    unordered_map<int, list<int> > adj;

    void addEdge(int v, int u, int direction) {

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
            }
            cout << endl;
        }

    }


};

void BSF(int node, unordered_map<int, list<int> > adj,unordered_map<int, bool> &visited, vector<int> &ans) {

    queue<int> q;
    q.push(node);
    visited[0] = 1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i : adj[front]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
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
    
    g.print();

    cout << "BSF travesal -" << endl;

    vector<int> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<n; i++) { 
        if(!visited[i]) { //cout << "hi";
            BSF(i, g.adj, visited, ans);
        }
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}