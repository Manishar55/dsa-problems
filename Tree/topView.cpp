
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

void printTopView(Node*root){
    if(root==NULL)
    return;

    //map for storing hd and topNode->data
    map<int, int>topNode;

    //level order traversal
    //we will store a pair consisting of node and horizontal distance
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int>temp=q.front();
        q.pop();

        Node*frontNode=temp.first;
        int hd=temp.second;

        //check if horizontal distance already exist
        if(topNode.find(hd)==topNode.end()){
            topNode[hd]=frontNode->data; //creating an entry
        }

        if(frontNode->left)
        q.push(make_pair(root->left, hd-1));

        if(frontNode->right)
        q.push(make_pair(root->right, hd+1));
    }

    //ans will store in the map
    cout<<"Printing the ans"<<endl;
    for(auto i: topNode){
        cout<<i.first<<"->"<<i.second<<endl;
    }
}

int main(){
    Node*root=buildTree();
    printTopView(root);
    return 0;
}