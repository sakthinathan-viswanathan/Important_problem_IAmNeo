// You are using GCC
#include<bits/stdc++.h>
using namespace std;

struct Node{
    
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


Node* insertTree(Node* temp,int val){
    
    if(temp == nullptr){
        temp = new Node(val);
        return temp;
    }
    
    if(temp->data > val){
        temp->left = insertTree(temp->left,val);
    }
    else
    {
       temp->right = insertTree(temp->right,val);
    }
    
    return temp;
    
    
}

void preOrder(Node* temp){
    
    if(temp == nullptr){
        return ;
    }
    
    
    cout<<temp->data<<" ";
    preOrder(temp->left);
    preOrder(temp->right);
    
    
}

void inOrder(Node* temp){
    if(temp == nullptr){
        return ;
    }
    
    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);
    
  
}

void postOrder(Node* temp){
    if(temp == nullptr){
        return ;
    }
    
    postOrder(temp->left);
    postOrder(temp->right);
    cout<<temp->data<<" ";
    
    
}

void levelOrder(Node* temp){
    if(temp == nullptr){
        return ;
    }
    
    queue<Node*>que;
    que.push(temp);
    
    while(!que.empty()){
        
        int n = que.size();
        
        for(int i=0;i<n;i++){
            Node* node = que.front();
            que.pop();
            
            cout<<node->data<<" ";
            
            if(node->left != nullptr){
                que.push(node->left);
                
            }
           
           if(node->right != nullptr){
               que.push(node->right);
           }
        }
    }
    
    
    
    
}




int main(){
    
    int n;
    cin>>n;
    
    vector<int>arr(n);
    
    Node* root = nullptr;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
       root =  insertTree(root,arr[i]);
    }
    
    preOrder(root);
     cout<<endl;
    inOrder(root);
     cout<<endl;
    postOrder(root);
     cout<<endl;
    levelOrder(root);
    
   
}
