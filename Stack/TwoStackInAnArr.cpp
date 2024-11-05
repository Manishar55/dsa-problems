
#include<iostream>
using namespace std;

class stack{
    public:

    int*arr;
    int size;
    int top1;
    int top2;

    stack(int size){

        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }

    //functions
    void push1(int data){
        if(top2-top1==1){
            cout<<"Overflow"<<endl; 
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"Underflow in stack 1"<<endl;
        }
        else{
            top1--;
        }
    }
    void push2(int data){
        if(top2-top1==1){
            cout<<"Overflow"<<endl; 
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }
    void pop2(){
        if(top2==size){
            cout<<"Underflow in stack 2"<<endl;
        }
        else{
            top2++;
        }
    }
    void print(){
        cout<<"top1 "<<top1<<endl;
        cout<<"top2 "<<top2<<endl;

        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main(){
    stack s(6);

    s.push1(5);
    s.push1(10);
    s.push2(15);
    s.push2(20);
    s.push2(25);
    s.push1(30);

    s.print();
    // s.pop1();

    // s.pop2();
}