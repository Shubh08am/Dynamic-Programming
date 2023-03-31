#include <bits/stdc++.h> 
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
