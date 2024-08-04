
class Solution{
public:
    vector<int> minPartition(int v)
    {
        int arr[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n=10;
        // code here
        vector<int>ans;
        
        for(int i=n-1; i>=0; i-- ){
            while(v>=arr[i]){
                v-=arr[i];
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};