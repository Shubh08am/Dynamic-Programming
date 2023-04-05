class Solution{
public:
    //Function to return max value that can be put in knapsack of capacity W.
     //Approach-1 Recursion
    int solve(int ind,int W ,int wt[] , int val[]){
        
        if(ind==0){ 
            //No. of ways to steal is W/wt[0] 
            //and total value is val[0]*W/wt[0] 
            return val[0]*(W/wt[0]) ; //still possible to steal 
        }
        
        int notTake = 0 + solve(ind-1,W,wt,val) ; 
        int take = 0 ; 
        //if possible to steal take it and stay at same index as infinite supply
        if(wt[ind]<=W) take = val[ind] + solve(ind,W-wt[ind],wt,val);
        return max(take,notTake) ;
    }
  //Approach-2 Memoization Time Complexity: O(N*W) , Space Complexity: O(N*W) + O(N)
    int solve2(int ind,int W ,int wt[] , int val[],vector<vector<int>>&dp){
        
        if(ind==0){
           return val[0]*(W/wt[0]) ; //still possible to steal 
         }
        
        if( dp[ind][W]!=-1) return dp[ind][W] ;
        
        int notTake = 0 + solve2(ind-1,W,wt,val,dp) ; 
        int take = 0 ; 
        //if possible to steal take it and stay at same index as infinite supply 
        if(wt[ind]<=W) take = val[ind] + solve2(ind,W-wt[ind],wt,val,dp);
        return dp[ind][W]=max(take,notTake) ;
    }
    //Approach-3 Tabulation Time Complexity: O(N*W) , Space Complexity: O(N*W)
    int tabulation(int W, int wt[], int val[],vector<vector<int>>&dp,int n){
        //bottom-up approach from base case(0) to up(till n-1)
        //base case 
        //for ind=0 W varies from wt[0] to W
        for(int currWt=0;currWt<=W;currWt++) {
            dp[0][currWt] = val[0]*(currWt/wt[0]) ; 
             
        }
        
        //for ind=1 onwards and W varies from 0 to W 
        for(int ind=1;ind<n;ind++){
            for(int currWt=0;currWt<=W;currWt++){
                int notTake = 0 + dp[ind-1][currWt] ; 
                 int take = INT_MIN ; 
                 //if possible to steal 
                 if(wt[ind]<=currWt) take = val[ind] + dp[ind][currWt-wt[ind]];
                  dp[ind][currWt]=max(take,notTake) ;
            }
        }
        return dp[n-1][W] ; //as recursion call made from (n-1,W)
    }
    
    //Approach-4 Tabulation with Space Optimization Time Complexity: O(N*W) , Space Complexity: O(2*W)
    int tabulationWithSpaceOptimization(int W, int wt[], int val[],int n){
        //bottom-up approach from base case(0) to up(till n-1)
        vector<int>prev(W+1,0) , curr(W+1,0) ; //using 2 arrays
        for(int currWt=wt[0];currWt<=W;currWt++) prev[currWt] = val[0]*(currWt/wt[0]) ; 
        
        //for ind=1 onwards and W varies from 0 to W 
        for(int ind=1;ind<n;ind++){
             for(int currWt=0;currWt<=W;currWt++){// (right to left going in prev) 
                int notTake = 0 + prev[currWt] ; 
                 int take = INT_MIN ; 
                  //if possible to steal take it and stay at same index as infinite supply
                 //take and remain on same index therefore use curr and not prev
                 if(wt[ind]<=currWt) take = val[ind] + curr[currWt-wt[ind]];
                  curr[currWt]=max(take,notTake) ;
            }
            prev=curr;//update previous row to current row
        }
        return prev[W] ; //as recursion call made from (n-1,W)
    }
    //Approach-5 Tabulation with Space Optimization Time Complexity: O(N*W) , Space Complexity: O(W)
    int tabulationWithSpaceOptimization2(int W, int wt[], int val[],int n){
        //bottom-up approach from base case(0) to up(till n-1)
        vector<int>prev(W+1,0); //using 1 arrays
        for(int currWt=0;currWt<=W;currWt++) prev[currWt] = val[0]*(currWt/wt[0]) ; 
        
        //for ind=1 onwards and W varies from 0 to W 
        for(int ind=1;ind<n;ind++){
           for(int currWt=0;currWt<=W;currWt++){// (right to left going in prev) 
                int notTake = 0 + prev[currWt] ; 
                 int take = INT_MIN ; 
                  //if possible to steal take it and stay at same index as infinite supply
                 if(wt[ind]<=currWt) take = val[ind] + prev[currWt-wt[ind]];
                 //updating curr[currWt] value in prev row only  
                 //and currWt-wt[ind] indicates only left part is needed while filling 
                   prev[currWt]=max(take,notTake) ;
            }
        }
        return prev[W] ;
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
    //return solve(n-1,W,wt,val);//Approach-1 Recursion
     
    // vector<vector<int>>dp(n,vector<int>(W+1,-1));
      //return solve2(n-1,W,wt,val,dp);//Approach-2 Memoization
     
    // vector<vector<int>>dp(n,vector<int>(W+1,0));
    // return tabulation(W,wt,val,dp,n);//Approach-3 Tabulation
        
     // return tabulationWithSpaceOptimization(W,wt,val,n);//Approach-4 tabulationWithSpaceOptimization
     
    return tabulationWithSpaceOptimization2(W,wt,val,n);//Approach-5 tabulationWithSpaceOptimization
    }
};
