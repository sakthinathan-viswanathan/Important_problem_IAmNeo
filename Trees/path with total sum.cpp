// You are using GCC
#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
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
            
            if(temp ->left != nullptr){
                temp = temp->left;
                
            }
            else
            {
                temp->left = new Node(val);
                return ;
            }
        }
        else{
            
            if(temp ->right != nullptr){
                temp = temp->right;
                
            }
            else
            {
                temp->right = new Node(val);
                return ;
            }
        }
    }
    
}

vector<int>res;

void pathAndSum(Node* temp,int sum){
    
    if(temp == nullptr){
        return ;
    }
    
    res.push_back(temp->data);
    sum += temp->data;
    
    if(!temp->left && !temp->right){
        
        for(int i:res){
            cout<<i<<" ";
        }
        cout<<" -> "<<sum<<endl;
    } 
    
    pathAndSum(temp->left,sum);
    pathAndSum(temp->right,sum);
    
    res.pop_back();
}




int main(){
    
    int n;
    cin>>n;
    
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        
        cin>>arr[i];
        insertTree(arr[i]);
    }
    
    
    pathAndSum(root,0);
    
    
    
}
