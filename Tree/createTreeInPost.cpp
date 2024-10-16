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
Node*buildTreeFromIorderPostorder(int inorder[], int postorder[], int size, int &postindex, int inorderStart, int inorderEnd){

        //base case
        if(postindex<0 || inorderStart > inorderEnd){
            return NULL;
        }

        //step A
        int element = postorder[postindex--];
        Node*root=new Node(element);
        int pos=findPos(inorder, size, element);

        //step B -> root->right solve
        root->right=buildTreeFromIorderPostorder(inorder, postorder, size, postindex, pos+1, inorderEnd);

        //step C -> root->left solve
        root->left=buildTreeFromIorderPostorder(inorder, postorder, size, postindex, inorderStart, pos-1);

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
    int inorder[]={40, 20, 10, 50, 30, 60};
    int postorder[]={40, 20, 50, 60, 30, 10};

    int size=6;
    int postindex=size-1;
    int inorderStart=0;
    int inorderEnd=size-1;

    cout<<"building tree : "<<endl;
    Node*root=buildTreeFromIorderPostorder(inorder, postorder, size, postindex, inorderStart, inorderEnd);
    cout<<"Priting "<<endl;
    levelOrderTraversal(root);
}