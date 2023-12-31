class Solution {
public:
    const int mod=1e9+7;
    int dp[31][1001];
    int solve(int n,int k,int target){
        if(target==0){
            if(n==0) return 1;
            else return 0;
        }
        if(target<0 || n<0) return 0;
        int &ans=dp[n][target];
        if(ans!=-1) return ans;
        ans=0;
        //total k faces
        for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,target-i))%mod;
        }
    return ans;
    }
    int tabulation(int n,int k,int target){
        vector<vector<int>> dp(n+1,vector<int>(target+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                int ans = 0;
                for(int z=1; z<=k; z++){
                    if(j>=z) ans = (ans + dp[i-1][j-z]) % mod;
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
       // memset(dp,-1,sizeof(dp));
       // return solve(n,k,target);
       return tabulation(n,k,target);
    }
};
