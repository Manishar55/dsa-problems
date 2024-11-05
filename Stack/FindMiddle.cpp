
#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>&st, int & totalSize){
    if(st.size()==0){
        cout<<"Stack is empty"<<endl;
        return;
    }
    if(st.size()==totalSize/2+1){
        cout<<"Middle element is: "<<st.top()<<endl;
        return;
    }
    int temp=st.top();
    st.pop();

    //res call
    printMiddle(st, totalSize);

    //backtrack
    st.push(temp);
}

int main(){
    //creation
    stack<int>s;

    //insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    int totalSize=s.size();
    printMiddle(s, totalSize);
}