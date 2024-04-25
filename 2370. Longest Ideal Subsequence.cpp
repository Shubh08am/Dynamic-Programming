class Solution {
public:
    int solve(int ind,int prev,int &k,string &s,vector<vector<int>>&dp){
        int n=s.size();
        if(ind==n) return 0; 
        int &val=dp[ind][prev+1];
        if(val!=-1) return val ;
        
        int notTake=solve(ind+1,prev,k,s,dp);
        int take=0;
        if(prev==-1 || abs((s[ind]-'a')-prev)<=k){
            take=1+solve(ind+1,(s[ind]-'a'),k,s,dp);
        }
    return val=max(take,notTake);
    } 
    int tabulation(string s,int k,int n){
        vector<vector<int>>dp(n+1,vector<int>(27,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=-1;prev<=25;prev++){
                    int notTake = dp[ind+1][prev+1];
                    int take=0;
                    if(prev==-1 || abs((s[ind]-'a')-prev)<=k){
                            take=1+dp[ind+1][(s[ind]-'a')+1];
                    }
                dp[ind][prev+1]=max(take,notTake);
            }
        }
     return dp[0][0];
    }
    int tabulationSpaceOptimization(string s,int k,int n){
        vector<int>dp(27,0);
        
        for(int ind=n-1;ind>=0;ind--){
            vector<int>next(27,0);
            for(int prev=-1;prev<=25;prev++){
                    int notTake = dp[prev+1];
                    int take=0;
                    if(prev==-1 || abs((s[ind]-'a')-prev)<=k){
                            take=1+dp[(s[ind]-'a')+1];
                    }
                next[prev+1]=max(take,notTake);
            }
            dp=next;
        }
     return dp[0];
    }
    int longestIdealString(string s, int k) {
        //take not take 
        int n = s.size() ; 
      //  vector<vector<int>>dp(n+1,vector<int>(27,-1));
     //   return solve(0,-1,k,s,dp);
        
     //   return tabulation(s,k,n);
        
        return tabulationSpaceOptimization(s,k,n);
    }
};
