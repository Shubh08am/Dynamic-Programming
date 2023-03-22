//Problem Link:- https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
#include <bits/stdc++.h> 
    //memoization approach -> S.C ->O(N)+O(N) & T.C-> O(N)
 /*   int solve(int ind,vector<int>&nums,vector<int>&dp){
       if(ind==0) return nums[0];
       if(ind<0) return 0 ; 
       if(dp[ind]!=-1) return dp[ind];
       int pick = nums[ind] + solve(ind-2,nums,dp);
       int notpick = 0+solve(ind-1,nums,dp); 
       return dp[ind]=max(pick,notpick);
   }
int maximumNonAdjacentSum(vector<int> &nums){
     //dp on subsequences 
       int n = nums.size();
       vector<int>dp(n,-1);
       return solve(n-1,nums,dp); 
}*/
    //Tabulation approach(bottom up) -> S.C ->O(N) & T.C-> O(N) 
/*
int maximumNonAdjacentSum(vector<int> &nums){
     //dp on subsequences 
        int n = nums.size();
       vector<int>dp(n,-1);
       dp[0]=nums[0]; //from base case 
       for(int i=1;i<n;i++){
           int pick = nums[i] ; 
           if(i>1) pick+=dp[i-2] ;  //from recurrence relation
           int notpick = 0+dp[i-1] ;
           dp[i] = max(pick,notpick);
       }
       return dp[n-1]; 
}*/
 //Tabulation approach(bottom up) -> S.C ->O(1) & T.C-> O(N)
int maximumNonAdjacentSum(vector<int> &nums){
     int n = nums.size();
       int prev=nums[0] , prev2=0; //from base case 
        for(int i=1;i<n;i++){
           int pick = nums[i] ; 
           if(i>1) pick+=prev2 ;  //from recurrence relation
           int notpick = 0+prev;
           int curri = max(pick,notpick);
           prev2=prev;
           prev=curri;
       }
       return prev;
}
