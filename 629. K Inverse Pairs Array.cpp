class Solution {
public:
    const int mod = 1e9+7;
    int solve(int n,int k,vector<vector<int>>&dp){
        if(k==0) return 1;
        if(k<0 || n<0) return 0;
        int &val=dp[n][k];
        if(val!=-1) return val;
        val=0;
        for(int i=0;i<=k;i++){
            if(n>i && k>=i)
            val=(val+solve(n-1,k-i,dp))%mod;
        }
    return val;
    }
    int kInversePairs(int n, int k) {
        /*
        1 2 3 4 

        --> 1 _ _ _ = n-1,k 
        --> 2 _ _ _ = n-1,k-1 as after 2 , 1 will be there so 1 pair found 
        --> 3 _ _ _ = n-1,k-2 as after 3 , 2 1 will be there so 2 pair found 
        --> 4 _ _ _ = n-1,k-3 as after 4,3 2 1 will be there so 3 pair found 

        --> _ _ _ _ = (n-1,k-i) --> i pair found 

        */
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};
