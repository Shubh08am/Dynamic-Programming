#include <bits/stdc++.h> 
 //Approach-1 Recursion Time Complexity: O(2^N)[Exponential] [greater than it as we stay at ind after take operation] 
    // Space Complexity: O(w) [In worst case] and not O(N) [as we stay at ind after take operation]
int solve(int ind,int w, vector<int> &profit, vector<int> &weight){
    int n = profit.size();
    if(ind==n-1){ 
            //No. of ways to steal is W/weight[n-1] 
            //and total value is profit[n-1]*W/weight[n-1] 
        return profit[n-1]*(w/weight[n-1]);
    }
    int notTake = solve(ind+1,w,profit,weight) ; 
    int take = INT_MIN;
     //stay at ind position only as we may use it again on reduced target
    if(weight[ind]<=w) take = profit[ind]+solve(ind,w-weight[ind],profit,weight);
    return max(take,notTake);
}
//Approach-2 Memoization Time Complexity: O(N*W) , Space Complexity: O(N*W) + O(W)
int solve2(int ind,int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
    int n = profit.size();
    if(ind==n-1){
        //No. of ways to steal is W/weight[n-1] 
        //and total value is profit[n-1]*W/weight[n-1] 
        return profit[n-1]*(w/weight[n-1]);
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake = solve2(ind+1,w,profit,weight,dp) ; 
    int take = INT_MIN;

    //stay at ind position only as we may use it again on reduced target
    if(weight[ind]<=w) take = profit[ind]+solve2(ind,w-weight[ind],profit,weight,dp);
    return dp[ind][w]=max(take,notTake);
}
//Approach-3 Tabulation Time Complexity: O(N*W) , Space Complexity: O(N*W)
int tabulation(int w, vector<int> &profit, vector<int> &weight){
    int n = profit.size();
    vector<vector<int>>dp(n,vector<int>(w+1,0));
  //Recursion call from(0,w) i.e tabulation from ind = n-1
  //(base-case [bottom]) to 0([Up]) & target = 0 to target

    //for ind=n-1 base case :- w varies from 0 to amount
    for(int wt=0;wt<=w;wt++){
        dp[n-1][wt] = profit[n-1]*(wt/weight[n-1]);
    }
    
    //for ind=n-1 done start from ind=n-2 
    for(int ind=n-2;ind>=0;ind--){
        for(int wt=0;wt<=w;wt++){
            int notTake = dp[ind+1][wt];
            int take = INT_MIN;
             //stay at ind position only as we may use it again on reduced target
            if(weight[ind]<=wt) take = profit[ind]+dp[ind][wt-weight[ind]];
            
             dp[ind][wt]=max(take,notTake);
        }
    }
    return dp[0][w];//as Recursion call from(0,amount)
}
int tabulationWithSpaceOptimization(int w, vector<int> &profit, vector<int> &weight){
    int n = profit.size();
    vector<int>prev(w+1,0),curr(w+1,0);

    //for ind=n-1 base case :- amount varies from 0 to amount
    for(int wt=0;wt<=w;wt++){
        prev[wt] = profit[n-1]*(wt/weight[n-1]);
    }

      //for ind=n-1 done start from ind=n-2 
    for(int ind=n-2;ind>=0;ind--){
        for(int wt=0;wt<=w;wt++){
            int notTake = prev[wt];
            int take = INT_MIN;
            //stay at ind position only as we may use it again on reduced target
            //since,at position=ind we use curr and not prev
            if(weight[ind]<=wt) take = profit[ind]+curr[wt-weight[ind]];
            
             curr[wt]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[w];
}

int tabulationWithSpaceOptimization2(int w, vector<int> &profit, vector<int> &weight){
    int n = profit.size();
    vector<int>prev(w+1,0);
    //for ind=n-1 base case :- amount varies from 0 to amount
    for(int wt=0;wt<=w;wt++){
        prev[wt] = profit[n-1]*(wt/weight[n-1]);
    }
    
     //for ind=n-1 done start from ind=n-2
    for(int ind=n-2;ind>=0;ind--){
        for(int wt=0;wt<=w;wt++){
            int notTake = prev[wt];
            int take = INT_MIN;
            //stay at ind position only as we may use it again on reduced target
            if(weight[ind]<=wt) take = profit[ind]+prev[wt-weight[ind]];
            
        //overwrite curr value in prev as for calculating curr[ind] 
        //we don't need left guy of prev[ind] only same column guy of curr[ind] i.e prev[ind]
        //thus,all left value from prev[ind] is not used therefore we can directly update
             prev[wt]=max(take,notTake);
        }
    }
    return prev[w];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // return solve(0,w,profit,weight); 

   // vector<vector<int>>dp(n,vector<int>(w+1,-1));
   // return solve2(0,w,profit,weight,dp);//Approach-2 Memoization

   //return tabulation(w,profit,weight);//Approach-3 Tabulation
   
 //  return tabulationWithSpaceOptimization(w,profit,weight);//Approach-4 tabulationWithSpaceOptimization[Two array Used]
 return tabulationWithSpaceOptimization2(w,profit,weight); ////Approach-5 tabulationWithSpaceOptimization[Single array Used]
}
