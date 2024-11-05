 void InsertAtBottom(stack<int>&st, int target){
        if(st.empty()){
            st.push(target);
            return;
        }
        int topElement=st.top();
        st.pop();
        
        //Rec
        InsertAtBottom(st, target);
        
        //Backtrack
        st.push(topElement);
        
    }
    void Reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
        int target=st.top();
        st.pop();
        
        //rec
        Reverse(st);
        
        //insert target at bottom
        InsertAtBottom(st, target);
    }