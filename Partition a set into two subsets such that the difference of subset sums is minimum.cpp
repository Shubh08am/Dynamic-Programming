#include <bits/stdc++.h>
/* // APPROACH-1 Tabulation :- Time Complexity: O(N*totSum) +O(N) +O(N) 
//Space Complexity: O(N*totSum)
 int minSubsetSumDifference(vector<int>& nums, int n)
{
	         //tabulation :- fails for -ve number
        int totalSum = 0   ; 
        for(auto&val:nums) totalSum+=val;
        vector<vector<bool>>dp(n,vector<bool>(totalSum+1,0));
            //here,recursive call from (0,totalSum)
       for(int i=0;i<n;i++) dp[i][0] = true; //for target=0 
       if(nums[0]<=totalSum) dp[0][nums[0]] = true ;  //for ind=0
      
        //for ind=1 onwards
       for(int ind=1;ind<n;ind++){
            for(int target=1;target<=totalSum;target++){
                   bool notTake = dp[ind-1][target];
                   bool take=false;
                   if(nums[ind]<=target) take = dp[ind-1][target-nums[ind]];

                   dp[ind][target] = notTake || take;
            }
       }
       int minDiff = INT_MAX ; 
       //check,last row from tabulation table logic if at that index = true 
       //that means that much target(sum) is possible till that index 
       //or till totalSum -> both works (slight optimization therefore till totalSum/2)
       for(int s1=0;s1<=totalSum;s1++){
           if(dp[n-1][s1]==true){
                 int s2 = totalSum-s1 ; 
                 minDiff = min(minDiff,abs(s2-s1)) ;
                }
           //     cout<<minDiff<<"\n" ; 
        }
       return minDiff;
}

*/
//APPROACH-2 Memoization Time Complexity: O(N*totSum) +O(N) +O(N) 
//Space Complexity: O(N*totSum) + O(N)
/*
bool subsetSumUtil(int ind, int target, vector<int> & arr, 
vector<vector<int>>& dp) {
  if (target == 0)
    return  dp[ind][target]= true;

  if (ind == 0)
    return dp[ind][target] = (arr[0] == target);

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

  bool taken = false;
  if (arr[ind] <= target)
    taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken || taken;
}
 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	   int totSum = 0;
  for (int i = 0; i < n; i++) {
    totSum += arr[i];}

  vector<vector<int>>dp(n,vector<int>(totSum + 1, -1));

  for (int i = 0; i <= totSum; i++) {
     subsetSumUtil(n - 1, i, arr, dp);
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}*/
//APPROACH-3 Tabulation  Space Optimization:- Time Complexity: O(N*totSum) +O(N) +O(N) 
//Space Complexity: O(totSum)
 int minSubsetSumDifference(vector<int>& nums, int n)
{
	         //tabulation :- fails for -ve number
        int totalSum = 0   ; 
        for(auto&val:nums) totalSum+=val;
        vector<bool>prev(totalSum+1,0),curr(totalSum+1,0);
            //here,recursive call from (0,totalSum)
       prev[0] = curr[0] = true; //for target=0 
       if(nums[0]<=totalSum) prev[nums[0]] = true ;  //for ind=0
      
        //for ind=1 onwards
       for(int ind=1;ind<n;ind++){
            for(int target=1;target<=totalSum;target++){
                   bool notTake = prev[target];
                   bool take=false;
                   if(nums[ind]<=target) take = prev[target-nums[ind]];

                   curr[target] = notTake || take;
            }
			prev=curr;
       }
       int minDiff = INT_MAX ; 
       //check,last row from tabulation table logic if at that index = true 
       //that means that much target(sum) is possible till that index 
       //or till totalSum -> both works (slight optimization therefore till totalSum/2)
       for(int s1=0;s1<=totalSum;s1++){
           if(prev[s1]==true){
                 int s2 = totalSum-s1 ; 
                 minDiff = min(minDiff,abs(s2-s1)) ;
                }
           //     cout<<minDiff<<"\n" ; 
        }
       return minDiff;
}
