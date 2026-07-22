#include<bits/stdc++.h>
using namespace std;



int main(){
    
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>adj(v);
    
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        
        adj[x].push_back(y);
        
    }
    
    vector<int>indegree(v);
    
    for(int i=0;i<v;i++){
        for(int nei:adj[i]){
            
            indegree[nei]++;
        }
    }
    
    queue<int>que;
    
   for(int i=0;i<v;i++){
       if(indegree[i] == 0){
           que.push(i);
       }
   }
   
   
   int count = 0;
   
   while(!que.empty()){
       
       int node = que.front();
       que.pop();
       
       count++;
       
       for(int nei:adj[node]){
           
           indegree[nei]--;
           
           if(indegree[nei] == 0){
               que.push(nei);
           }
       }
       
   }
   
   
   if(count == v){
       cout<<"No Cycle Exists...";
   }
   else{
       cout<<"Cycle Exists..";
   }
}
