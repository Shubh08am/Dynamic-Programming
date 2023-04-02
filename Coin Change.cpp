//problem link:- https://practice.geeksforgeeks.org/problems/coin-change2448/1 
class Solution {
  public:
  //Approach-2 Memoization :- Time Complexity: O(N*amount) Space Complexity: O(N*amount) + O(N)
    long long int solve2(int ind,int coins[], int amount,vector<vector<long long int>>&dp,int n){
           //when amount exhausted 
           if(amount==0) return 1;
           if(ind==n-1){
              //if by using that last coin amount can be exhausted 
              if(amount%coins[n-1]==0) return amount/coins[n-1];
              return 0;
          } 
            if(dp[ind][amount]!=-1)  return dp[ind][amount] ; 
          //Explore all the ways 
          long long int notTake=0,take=0;
              notTake = solve2(ind+1,coins,amount,dp,n) ; 
              if(coins[ind]<=amount) take = solve2(ind,coins,amount-coins[ind],dp,n) ; 
         //     cout<<notTake<<" "<<take<<"\n" ; 
          return dp[ind][amount] = take+notTake ;
    }
    long long int count(int coins[], int n, int amount) {

        vector<vector<long long int>>dp(n,vector<long long int>(amount+1,-1));
       long long int coin2 = solve2(0,coins,amount,dp,n);
       return coin2 ; //Approach-2 Memoization
    }
};
