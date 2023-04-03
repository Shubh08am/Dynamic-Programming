#include <bits/stdc++.h>
//Approach-1 Recursion (TLE)  (from 0 call)
 int solve(int ind,int tar,vector<int> &num){
     int n = num.size();
     if(ind==n-1){
        if(num[n-1]==0 && tar==0) return 2;
         if(num[n-1]==tar || tar==0) return 1;
         return 0;
    }
    int take = 0 ; 
    if(num[ind]<=tar) take=solve(ind+1,tar-num[ind],num) ; 
    int notTake = solve(ind+1,tar,num) ;  
    return take+notTake;
}
//Approach-1 Recursion (from n-1 call)
 int solve3(int ind,int tar,vector<int> &num){
     int n = num.size();
     if(ind==0){
        if(num[0]==0 && tar==0) return 2;
         if(num[0]==tar || tar==0) return 1;
         return 0;
    }
    int take = 0 ; 
    if(num[ind]<=tar) take=solve3(ind-1,tar-num[ind],num) ; 
    int notTake = solve3(ind-1,tar,num) ;  
    return take+notTake;
}

 //Approach-2 Memoization Time Complexity: O(N*tar) , Space Complexity:O(N*tar)+ O(N)
 //(from 0 call)
 int solve2(int ind,int tar,vector<int> &num,vector<vector<int>>&dp){
     int n = num.size();
     if(ind==n-1){
        if(num[n-1]==0 && tar==0) return 2;
         if(num[n-1]==tar || tar==0) return 1;
         return 0;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar] ;
    int take = 0 ; 
    if(num[ind]<=tar) take=solve2(ind+1,tar-num[ind],num,dp) ; 
    int notTake = solve2(ind+1,tar,num,dp) ;  
    return dp[ind][tar] =  take+notTake;
}
//Approach-2 Memoization (from n-1 call)
 int solve4(int ind,int tar,vector<int> &num,vector<vector<int>>&dp){
     int n = num.size();
     if(ind==0){
        if(num[0]==0 && tar==0) return 2; //both pick & notpick cases
         if(num[0]==tar || tar==0) return 1; //nums[0]==tar -> pick case && tar==0 -> notpick case
         return 0;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar] ;
    int take = 0 ; 
    if(num[ind]<=tar) take=solve4(ind-1,tar-num[ind],num,dp) ; 
    int notTake = solve4(ind-1,tar,num,dp) ;  
    return dp[ind][tar] =  take+notTake;
}
  //Approach-3 Tabulation Time Complexity:  O(N*tar) , Space Complexity:O(N*tar)
 //(from 0 call)
int tabulation(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=n-1 
   // if((num[n-1]==0 && tar==0) || (num[n-1]==0 && tar!=0 )) dp[n-1][0] = 2 ; //both pick & notpick cases
     if(num[n-1]==0) dp[n-1][0] = 2 ; //both pick & notpick cases
   // if(num[n-1]!=0 && tar!=0) dp[n-1][0] = 1 ; //notpick case
      else  dp[n-1][0] = 1 ; 
    if(num[n-1]!=0 && num[n-1]<=tar) dp[n-1][num[n-1]] = 1 ; //pick case 

    //for ind=n-2 onwards 
    for(int ind=n-2;ind>=0;ind--){
        for(int target=0;target<=tar;target++){
            int notTake = dp[ind+1][target];
            int take=0;
            if(num[ind]<=target) take=dp[ind+1][target-num[ind]];

            dp[ind][target] = take+notTake;
        }
    }
    return dp[0][tar];
}

//Approach-3 Tabulation Time Complexity:  O(N*tar) , Space Complexity:O(N*tar)
 //(from n-1 call)
int tabulation2(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=0
   // if((num[0]==0 && tar==0) || (num[0]==0 && tar!=0 )) dp[0][0] = 2 ; //both pick & notpick cases
     if(num[0]==0) dp[0][0] = 2 ; //both pick & notpick cases
  //  if(num[0]!=0 && tar!=0) dp[0][0] = 1 ; //notpick case
      else dp[0][0] = 1; 
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1 ; //pick case 

    //for ind=1 onwards 
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=tar;target++){
            int notTake = dp[ind-1][target];
            int take=0;
            if(num[ind]<=target) take=dp[ind-1][target-num[ind]];

            dp[ind][target] = take+notTake;
        }
    }
    return dp[n-1][tar];
}
 //Approach-4 Tabulation with Space Optimization Time Complexity:  O(N*tar) , Space Complexity:O(tar)
 //(from 0 call)
int tabulationSpaceOptimization(vector<int> &num, int tar){
    int n = num.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=n-1 
   // if((num[n-1]==0 && tar==0) || (num[n-1]==0 && tar!=0 )) dp[n-1][0] = 2 ; //both pick & notpick cases
     if(num[n-1]==0) prev[0] = 2 ; //both pick & notpick cases
   // if(num[n-1]!=0 && tar!=0) prev[0] = 1 ; //notpick case
      else prev[0] = 1 ; 
    if(num[n-1]!=0 && num[n-1]<=tar) prev[num[n-1]] = 1 ; //pick case 

    //for ind=n-2 onwards 
    for(int ind=n-2;ind>=0;ind--){
        for(int target=0;target<=tar;target++){
            int notTake = prev[target];
            int take=0;
            if(num[ind]<=target) take=prev[target-num[ind]];

            curr[target] = take+notTake;
        }
        prev=curr;
    }
    return prev[tar];
}

//Approach-3 Tabulation Time Complexity:  O(N*tar) , Space Complexity:O(N*tar)
 //(from n-1 call)
int tabulationSpaceOptimization2(vector<int> &num, int tar){
    int n = num.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=0
   // if((num[0]==0 && tar==0) || (num[0]==0 && tar!=0 )) dp[0][0] = 2 ; //both pick & notpick cases
     if(num[0]==0) prev[0] = 2 ; //both pick & notpick cases
  //  if(num[0]!=0 && tar!=0) dp[0][0] = 1 ; //notpick case
      else prev[0] = 1; 
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1 ; //pick case 

    //for ind=1 onwards 
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=tar;target++){
            int notTake = prev[target];
            int take=0;
            if(num[ind]<=target) take=prev[target-num[ind]];

            curr[target] = take+notTake;
        }
        prev=curr;
    }
    return prev[tar];
}
int findWays(vector<int> &num, int tar)
{
    // return solve(0,tar,num) ;
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    // return solve(0,tar,num) ; //Approach-1 Recursion
   // return solve3(n-1,tar,num) ; //Approach-1 Recursion
   // return solve2(0,tar,num,dp); //Approach-2 Memoization
   // return solve4(n-1,tar,num,dp); //Approach-2 Memoization
   // return tabulation(num,tar) ; //Approach-3 Tabulation
   //   return tabulation2(num,tar) ;
   // return tabulationSpaceOptimization(num,tar) ; //Approach-4 Tabulation With S.O
    return tabulationSpaceOptimization2(num,tar) ; //Approach-4 Tabulation With S.O
}
