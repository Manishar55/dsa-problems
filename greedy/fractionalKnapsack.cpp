class Solution {
  public:
    bool static comp(Item a, Item b) {
        
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int w, Item arr[], int n) {
      sort(arr, arr + n, comp);
      
      double totalval = 0;
      
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= w) {
                totalval += arr[i].value;
                w-=arr[i].weight;
            } 
            else{
                totalval+=((arr[i].value/(double)arr[i].weight)*(double)w);                break;
            }
        }

      return totalval;    
        
    }
};