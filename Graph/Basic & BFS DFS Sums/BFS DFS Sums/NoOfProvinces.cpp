// Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
//To find number of components in graph
// if 9 nodes, 123 connected together, 4567 together and 89 together, so answer is 3 components

#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adjLs[], int vis[]){
    vis[node]=1;
    for(auto it:adjLs[node]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V) {
    
    // To change adjacency matrix to list
    vector<int>adjLs[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[V]={0};
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }
    }
    return cnt;
}