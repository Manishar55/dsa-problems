
#include<iostream>
using namespace std;

class stack{
    public:

    int *arr;
    int top;
    int size;

    stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }

    void push(int data){
        if(size-top>1){
            //space available->insert
            top++;
            arr[top]=data;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"can not delte element";
        }
        else{
            top--;
        }
    }

    int getTop(){
        if(top==-1){
            cout<<"There is no element in the stack";
        }
        else{
            return arr[top];
        }
    }
    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};    
int main(){
    //creation
    stack s(10);

    //insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(! s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"Size of stcak is "<<s.getSize()<<endl;
}