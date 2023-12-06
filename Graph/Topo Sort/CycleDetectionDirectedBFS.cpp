//detect cycle in directed graph using BFS
//same as Kahns algo topo sort DAG BFS

#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
    // code here
    vector<int> degree(V, 0); // it's for in_degree
    queue<int> q;
    int c =0;
    for (int i = 0; i < V; i++){
        for (auto it : adj[i])
            degree[it]++;
    }
    for (int i = 0; i < V; i++){
        if (degree[i] == 0)
            q.push(i);
    }
    while (!q.empty()){
        int top = q.front(); // front element of queue
        c++;
        q.pop();
        // node is in your topo sort so remove it from the indegree
        for (auto it : adj[top]){
            degree[it]--;
            if (degree[it] == 0)
                q.push(it);
        }
    }
    if (c == V)
        return false;
    return true;
}