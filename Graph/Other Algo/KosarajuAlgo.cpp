// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
// Find the number of strongly connected components in the graph.
#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<vector<int>> inverted;

//Function to find number of strongly connected components in the graph.
void dfs1(vector<vector<int>> &graph,int src,vector<int> &vis){
    vis[src]=true;
    for(auto node: graph[src])
        if(!vis[node]){
            dfs1(graph,node,vis);
        }
    st.push(src);
}

void reverse(vector<vector<int>> &graph){
    for(int i=0;i<graph.size();i++){
        for(auto node: graph[i]){
            inverted[node].push_back(i);
        }
    }
}

void dfs2(int src,vector<int> &vis){
    // cout<<src<<" ";
    vis[src]=true;
    for(auto node: inverted[src])
    if(!vis[node]){
        dfs2(node,vis);
    }
}

int kosaraju(int V, vector<vector<int>>& adj){
    vector<int> vis(V,false);
    for(int i=0;i<V;i++)
    if(!vis[i]){
    dfs1(adj,i,vis);  //load to stack
    }
    inverted.resize(V);
    
    reverse(adj);  //reverse direction of graph
    
    vector<int> vis2(V,false);
    int count=0;
    
    while(!st.empty()){   //traverse each component per iteration 
        int top=st.top();
        st.pop();
        if(!vis2[top]){
            dfs2(top,vis2);
            // cout<<endl;
            count++;   //get the count
        }
    }
    return count;
}
