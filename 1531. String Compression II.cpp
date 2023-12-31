int dp[101][27][101][101];
class Solution {
public:
    int solve(int ind,string&s,int k,int len,int prev){
        int n=s.size();
        if(ind==n) return k<0?1e8:0;
        if(k<0) return 1e8;
        int &ans = dp[ind][prev+1][len][k] ; 
        if(ans!=-1) return ans;
        ans=1e9;
        // NO DELETION CASE 
        if(prev==(s[ind]-'a')){
            ans = min(ans,(len==1||len==9||len==99?1:0)+solve(ind+1,s,k,len+1,prev))  ;
        }
        else ans = min(ans,1+solve(ind+1,s,k,1,(s[ind]-'a'))) ;

        //DELETION CASE 
        ans=min(ans,solve(ind+1,s,k-1,len,prev));
    return ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        //DP 
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,s,k,0,-1);
    }
};
