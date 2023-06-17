//User function template for C++
class Solution{
public:
	 #define ll long long 
	const int mod = 1e9+7;
	int solve(int index,int which , int n,vector<vector<int>>&dp){
	    if(index>=n) return 1; 
	    if(dp[index][which]!=-1) return dp[index][which] ; 
	    
	    int take = 0; 
	    //take alternate 1 i.e 010... 
	    if(which==0) take = solve(index+1,1,n,dp);
	    
	    int notTake = solve(index+1,0,n,dp) ; 
	 //   cout<<take<<" "<<notTake<<"\n";
	    return dp[index][which] = (take+notTake)%mod;
	}
	ll countStrings(int n) {
	  vector<vector<int>>dp(n,vector<int>(2,-1)) ; 
	  return solve(0,0,n,dp) ;
	}
};
