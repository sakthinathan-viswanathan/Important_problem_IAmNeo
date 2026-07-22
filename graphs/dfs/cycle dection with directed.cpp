// You are using GCC
#include<bits/stdc++.h>
using namespace std;

bool dectetCycle(int node,vector<bool> &recStack,vector<bool> &visited,vector<vector<int>> &adj){
    
    if(recStack[node]){
        return true;
    }
    
    if(visited[node]){
        return false;
    }
    
    
    recStack[node] = true;
    visited[node] = true;
    
    
    for(int nei:adj[node]){
        if(dectetCycle(nei,recStack,visited,adj)){
            return true;
        }
    }
    
    recStack[node] = false;
    
    return false;
}

int main(){
    
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>adj(v);
    
      for(int i = 0; i < e; i++){
            int u, x;
            cin >> u >> x;
            adj[u].push_back(x);
      }
    
    vector<bool>recStack(v);
    vector<bool>visited(v);
   
    bool found = false;
    
    for(int i=0;i<v;i++){
        
        if(!visited[i]){
             if(dectetCycle(i,recStack,visited,adj)){
                found = true;
                break;
            }
        }
        
    }
    
    
    if(found){
        cout<<"Cycle Dected..";
    }
    else
    {
        cout<<"No Cycle Dected..";
    }
}
