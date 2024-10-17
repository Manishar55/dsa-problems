

#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*buildTree(){
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    if(data==-1)
    return NULL;

    Node*root=new Node(data);
    cout<<"Enter the data for left of "<<data<<endl;
    root->left=buildTree();
    cout<<"Enter the data for right of"<<data<<endl;
    root->right=buildTree();

    return root;
}

void printRightTree(Node*root, vector<int>&ans, int level){
    if(root==NULL)
    return;

    if(level==ans.size()){
        ans.push_back(root->data);
    }
    
    printRightTree(root->right, ans, level+1); 
    printRightTree(root->left, ans, level+1);
}

int main(){
    Node*root=buildTree();
    vector<int>ans;
    int level=0;
    printRightTree(root, ans, level);
    
    cout<<"Printing the ans"<<endl;
    for(auto i: ans){
        cout<<i<<" "<<endl;
    }
}