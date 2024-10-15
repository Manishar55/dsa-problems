
#include<iostream>
#include<queue>
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
int findPos(int inorder[], int size, int element){
    for(int i=0; i<size; i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}

//build tree from inorder and postorder traversal
Node*buildTree(int inorder[], int preorder[], int size, int &preindex, int inorderStart, int inorderEnd){

    //base case
    if(preindex>=size || inorderStart > inorderEnd){
        return NULL;
    }

    //step A
    int element = preorder[preindex++];
    Node*root=new Node(element);
    int pos=findPos(inorder, size, element);

    //step B -> root->left solve
    root->left=buildTree(inorder, preorder, size, preindex, inorderStart, pos-1);

    //step C -> root->right solve
    root->right=buildTree(inorder, preorder, size, preindex, pos+1, inorderEnd);

    return root;
}
void levelOrderTraversal(Node*root){
    queue<Node*>q;

    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main(){
    int inorder[]={40, 20, 50, 10, 60, 30, 70};
    int preorder[]={10, 20, 40, 50, 30, 60, 70};

    int size=7;
    int preindex=0;
    int inorderStart=0;
    int inorderEnd=size-1;

    cout<<"building tree : "<<endl;
    Node*root=buildTree(inorder, preorder, size, preindex, inorderStart, inorderEnd);
    cout<<"Priting "<<endl;
    levelOrderTraversal(root);
}