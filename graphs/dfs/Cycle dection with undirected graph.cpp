#include<bits/stdc++.h>
using namespace std;

bool dectetCycle(int node,int parent,vector<bool> &visited,vector<vector<int>> &adj){
    
    visited[node] = true;
    
    for(int nei:adj[node]){
        
        if(!visited[nei]){
            if(dectetCycle(nei,node,visited,adj)){
                return true;
            }
        }
        else if(parent != nei){
            return true;
        }
    }
    
    return false;
}

int main(){
    
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>adj(v);
    
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool>vis(v);
    
    
    if(dectetCycle(0,-1,vis,adj)){
        cout<<"Cycle Dected..";
    }
    else
    {
        cout<<"No Cycle Dected..";
    }
}
