class Solution {
public:
    //APPROACH 1:-  PEAK VALLEY APPROACH (PEAK -> HIGHEST POINT) (VALLEY -> LOWEST POINT)
    // consider every peak immediately after a valley and take difference of peak and valley in profit 
    int peakValley(vector<int>&prices){
       int n = prices.size();
       int peak = prices[0] ;
       int valley = prices[0] ; 
       int profit=0;

       // peak -> prices[i]>prices[i+1] 
       // valley -> prices[i]<prices[i+1] 
        
        int i=0;
      while(i<n-1){
         //for valley 
          while(i<n-1 && prices[i]>=prices[i+1]) i++;
          valley = prices[i] ; 
       
         //for peak 
          while(i<n-1 && prices[i]<=prices[i+1]) i++;
          peak = prices[i] ; 
       
          profit+=(peak-valley);
      }
      return profit;
    }
    //APPROACH 2:-  PEAK VALLEY APPROACH EXTENSION 
    int peakValleyExtension(vector<int>&prices){
      int n = prices.size();
      int profit=0;

      for(int i=0;i<n-1;i++){
          int currProfit = prices[i+1] - prices[i] ; 
          int isProfitable = max(0,currProfit);
          profit+=isProfitable;
      }
      return profit;
    }
    int maxProfit(vector<int>& prices) {
      // return peakValley(prices); //APPROACH 1:-  PEAK VALLEY APPROACH
       return peakValleyExtension(prices); //APPROACH 1:-  PEAK VALLEY APPROACH EXTENSION
    }
};
