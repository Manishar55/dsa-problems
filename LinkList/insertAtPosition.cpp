#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        cout<<"Node with value"<<this->data<<" deleted"<<endl;
    }
};

void insertAtHead(Node*&head, Node*&tail, int data){

    //check for empty LL
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        //create a node
         Node*newNode=new Node(data);
         newNode->next=head;
         head=newNode;
    }
}

void insertAtTail(Node*&head, Node*&tail, int data){

    //check for empty LL
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        //create a node
         Node*newNode=new Node(data);
         tail->next=newNode;
         tail=newNode;
    }
}

int findLength(Node*&head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtPos(int data, int position, Node*&head, Node*&tail){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    //check if position is head or tail
    if(position==0){
        insertAtHead(head, tail, data);
        return;
    }
    int len=findLength(head);
    if(position>=len){
        insertAtTail(head, tail, data);
        return;
    }

    //step1: find prev and curr;
    int i=1;
    Node*prev=head;
    while(i<position){
        prev=prev->next;
        i++;
    }
    Node*curr=prev->next;

    Node*newNode=new Node(data);
    newNode->next=curr;
    prev->next=newNode;

}

void deleteNode(int position, Node*&head, Node*&tail){
    if(head==NULL){
        cout<<"Can not delete LL is empty"<<endl;
        return;
    }
    //deleting first node
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    int len=findLength(head);

    //deleting last node
    if(position==len){
        //find prev
        int i=1;
        Node*prev=head;
        while(i<position-1){
            prev=prev->next;
            i++;
        } 
        prev->next=NULL; 
        Node*temp=tail;
        tail=prev;
        delete temp;
        return;
    }

    //deleting middle node
    //find prev and curr node
    int i=1;
    Node*prev=head;
    while(i<position-1){
        prev=prev->next;
        i++;
    }
    Node*curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node*head=NULL;
    Node*tail=NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 98);
    insertAtTail(head, tail, 98);
    insertAtTail(head, tail, 90);

    insertAtPos(333, 5, head, tail);

    deleteNode(3, head, tail);

    print(head);
    cout<<endl;

    cout<<findLength(head)<<endl;
}