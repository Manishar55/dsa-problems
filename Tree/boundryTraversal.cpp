


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

void printLeftBoundry(Node*root, vector<int>&ans){
    if(root==NULL)
    return;

    //if root is a leaf node then go back
    if(root->left==NULL && root->right==NULL)
    return;

    ans.push_back(root->data);

    if(root->left){
        printLeftBoundry(root->left, ans);
    }
    else{
        printLeftBoundry(root->right, ans);
    }
}
void printLeafBoundry(Node*root, vector<int>&ans){
    if(root==NULL)
    return;

    //if root is a leaf node then go back
    if(root->left==NULL && root->right==NULL)
    ans.push_back(root->data);
    
    printLeafBoundry(root->left, ans);
    printLeafBoundry(root->right, ans);
    
}

void printRightBoundry(Node*root, vector<int>&ans){
    if(root==NULL)
    return;

    //if root is a leaf node then go back
    if(root->left==NULL && root->right==NULL)
    return;

    if(root->right){
        printRightBoundry(root->right, ans);
    }
    else{
        printRightBoundry(root->left, ans);
    }
    ans.push_back(root->data);
}
void boundryTraversal(Node*root, vector<int>&ans){
    if(root==NULL)
    return;
    ans.push_back(root->data);

    printLeftBoundry(root->left, ans);
    printLeafBoundry(root, ans);
    printRightBoundry(root->right, ans);
}
int main(){
    Node*root=buildTree();
    vector<int>ans;
    int level=0;
    boundryTraversal(root, ans);
    
    cout<<"Printing the ans"<<endl;
    for(auto i: ans){
        cout<<i<<" "<<endl;
    }
}

//i/p: 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1
//o/p :
// 10
// 20
// 30
// 90
// 80
// 60
// 110
// 130
// 120
// 100
// 40