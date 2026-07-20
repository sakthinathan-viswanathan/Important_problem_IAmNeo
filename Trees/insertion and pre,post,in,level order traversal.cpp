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

Node* root = nullptr;

void insertTree(int val){
    
    if(root == nullptr){
        root = new Node(val);
        return ;
    }
    
    Node* temp = root;
    
    while(temp != nullptr){
        
        if(temp->data > val){
            
            if(temp->left == nullptr){
                temp->left = new Node(val);
                return ;
            }
            else
            {
                temp = temp->left;
            }
            
        }
        else
        {
            
            if(temp->right == nullptr){
                temp->right = new Node(val);
                return ;
            }
            else
            {
                temp = temp->right;
            }
            
        }
        
    }
    
    return ;
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
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        insertTree(arr[i]);
    }
    
    preOrder(root);
     cout<<endl;
    inOrder(root);
     cout<<endl;
    postOrder(root);
     cout<<endl;
    levelOrder(root);
    
   
}
