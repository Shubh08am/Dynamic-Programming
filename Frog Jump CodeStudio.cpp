//Problem Link:- https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include <bits/stdc++.h> 
int solve(int index , int n, vector<int> &heights,vector<int> &dp){
  if(index==0) return 0;
  if(dp[index]!=-1) return dp[index] ; 
 //jump  one and jump2 
 int jump1 = INT_MAX , jump2 = INT_MAX ;
 jump1 = solve(index-1,n,heights,dp) +abs(heights[index]-heights[index-1]);
 //jump2 if index>1
 if (index>1){
 jump2 = solve(index-2,n,heights,dp) +abs(heights[index]-heights[index-2]);
}
return dp[index]=min(jump1,jump2);
}
int frogJump(int n, vector<int> &heights){
    //memoization approach
    /* 
    vector<int>dp(n,-1);
    return solve(n-1,n,heights,dp);
    */
  //Tabulation approach(bottom up) ->> S.C ->O(N) & T.C-> O(N) 
  /*  vector<int>dp(n,-1);
    dp[0]=0; 
    int jump1 = INT_MAX , jump2 = INT_MAX ;
    for(int i=1;i<n;i++){
        jump1 = dp[i-1] + abs(heights[i]-heights[i-1]);
        if(i>1){
        jump2 = dp[i-2] + abs(heights[i]-heights[i-2]);
}
        dp[i] = min(jump1,jump2);
        
    }
    return dp[n-1] ;
    */
//Tabulation approach(bottom up) ->> S.C ->O(1) & T.C-> O(N) 
   int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(heights[i]-heights[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(heights[i]-heights[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
  }

  return prev;
}
