
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(){
        this->data=0;
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node*newNode= new Node(data);
    newNode->next=head;
    head=newNode;
}

void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node*head=NULL;

    insertAtHead(head, 34);
     insertAtHead(head, 36);
      insertAtHead(head, 94);
       insertAtHead(head, 30);
        insertAtHead(head, 31);

    cout<<"Printing the LL"<<endl;
    print(head);
    return 0;
}