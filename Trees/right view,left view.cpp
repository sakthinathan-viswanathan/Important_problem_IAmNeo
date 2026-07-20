// You are using GCC
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




    
Node* insertTree(vector<int> &arr,int n,int i){
        
        
        if(i >= n || arr[i] == -1){
            return nullptr;
        }
        
        Node* node = new Node(arr[i]);
        
        node->left = insertTree(arr,n,i*2+1);
        node->right = insertTree(arr,n,i*2+2);
        
    return node;
    
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

void leftView(Node* temp){
    
    if(temp == nullptr){
        return ;
    }
    
    queue<Node*>q;
    q.push(temp);
    
    while(!q.empty()){
        
        int n = q.size();
        
        for(int i=0;i<n;i++){
            
            Node* node = q.front();
            q.pop();
            
            if(i == 0)
                cout<<node->data<<" ";
                
                
            if(node->left != nullptr){
                q.push(node->left);
            }
            
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
    }
}


void rightView(Node* temp){
    
    if(temp == nullptr){
        return ;
    }
    
    
    queue<Node*>q;
    q.push(temp);
    
    while(!q.empty()){
        
        int n = q.size();
        
        for(int i=0;i<n;i++){
            
            Node* node = q.front();
            q.pop();
            
            if(i == n-1){
                cout<<node->data<<" ";
            }
            
            
            if(node->left != nullptr){
                q.push(node->left);
            }
            
            if(node->right != nullptr){
                q.push(node->right);
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
    }
    
    root = insertTree(arr,n,0);
    
    cout<<"Left View: "<<endl;
    leftView(root);
    
    cout<<"\nRight View: "<<endl;
    rightView(root);
    
   
}
