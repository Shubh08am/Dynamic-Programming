class Solution{   
public:
//Approach-2 Memoization :- T.C = O(N*TARGET) S.C=O(N*TARGET) + O(N)
int solve(int ind,vector<int>&arr,vector<vector<int>>&dp, int sum){
    int n = arr.size();
    if(sum==0) return 1;
     if(ind==n-1) return arr[n-1]==sum;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int pick=0;
    if(arr[ind]<=sum)  pick =  solve(ind+1,arr,dp,sum-arr[ind]);
    int notPick = solve(ind+1,arr,dp,sum);

    return dp[ind][sum]=notPick||pick ;
}
//Approach-3 Tabulation T.C = O(N*TARGET) S.C=O(N*TARGET)
int tabulation(vector<int>&arr, int sum,vector<vector<bool>>&dp){
     int n = arr.size();
    //base case when sum=0 ind varies from 1 to n , for target=0
    for(int i=0;i<n;i++) dp[i][0] = true; 
    //when at last pos only for that target true , for i=n-1
    if(arr[n-1]<=sum) dp[n-1][arr[n-1]] = true; 
    
    //for ind = n-1 done see from ind=n-2 onwards and target=1 onwards as for target=0 all true done
    for(int ind=n-2;ind>=0;ind--){
        for(int target=1;target<=sum;target++){
            bool notPick = dp[ind+1][target] ; 
            bool pick=false;
            if(arr[ind]<=target)  pick =  dp[ind+1][target-arr[ind]]; 
            dp[ind][target]=notPick|pick ;
        }
    }
    return dp[0][sum] ;
} 
//Approach-4 Tabulation with Space Optimization Time Complexity: O(N*target) , Space Complexity:O(target)
int tabulationSpaceOptimization(vector<int>&arr, int sum){
     int n = arr.size();
     vector<int>prev(sum+1,0) , curr(sum+1,0);
 //    for(int i=0;i<n;i++) prev[0] = true;
       prev[0] = curr[0]=true;
    //when at last pos only for that target true , for i=n-1
    if(arr[n-1]<=sum) prev[arr[n-1]] = true; 
    
    //for ind = n-1 done see from ind=n-2 onwards and target=1 onwards as for target=0 all true done
    for(int ind=n-2;ind>=0;ind--){
        for(int target=1;target<=sum;target++){
            bool notPick = prev[target] ; 
            bool pick=false;
            if(arr[ind]<=target)  pick =  prev[target-arr[ind]]; 
            curr[target]=notPick|pick ;
        }
        prev=curr;
    }
    return prev[sum] ;
}
    bool isSubsetSum(vector<int>arr, int sum){ 
        int n = arr.size();
     //   vector<vector<int>>dp(n,vector<int>(sum+1,-1)) ; 
     //   return solve(0,arr,dp,sum); 
     
     // vector<vector<bool>>dp(n,vector<bool>(sum+1,false)) ; //Approach-tabulation 
      // return tabulation(arr,sum,dp); 
      
      return tabulationSpaceOptimization(arr,sum); //tabulationSpaceOptimization
    }
};
