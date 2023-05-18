#include <bits/stdc++.h> 
#define ll long long
const int mod = 1e9+7;
/*
Time Complexity: O(N*N*2 * N) ~ O(N3) There are a total of 2*N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

Space Complexity: O(2*N2) + Auxiliary stack space of O(N), 2*N2 for the dp array we are using.
*/
long long int f(int i,int j,int isTrue , string & exp ,vector<vector<vector<ll>>>&dp ){
    if(i>j) return 0;

    if(i==j){
        if(isTrue) return exp[i]=='T' ; 
        else return exp[i]=='F';
    }

    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue] ;

   ll ways = 0 ; 
   //from i+1 as when i=0 at i=1 we have operand and than at every 2 distnace 
    for(int ind = i+1 ; ind<=j-1;ind+=2){
           ll LT = f(i,ind-1,1,exp,dp) ; 
           ll LF = f(i,ind-1,0,exp,dp) ; 
           ll RT = f(ind+1,j,1,exp,dp) ; 
           ll RF = f(ind+1,j,0,exp,dp) ; 

           //see all operands now 
        if(exp[ind]=='&'){
            if(isTrue){
                ways= (ways+(LT*RT)%mod)%mod; 
            }
            else{
                ways=(ways+(LF*RF)%mod+(LF*RT)%mod+(LT*RF)%mod)%mod;
            }
        }   
        else if(exp[ind]=='|'){
            if(isTrue){
                ways= (ways+(LT*RT)%mod+ (LF*RT)%mod + (LT*RF)%mod )%mod ; 
            }
            else{
                ways=(ways+(LF*RF)%mod)%mod ;
            }
        } 
        else if(exp[ind]=='^'){
            if(isTrue){
                ways=( ways+ (LF*RT)%mod + (LT*RF)%mod )%mod ; 
            }
            else{
                ways=( ways+ (LF*RF)%mod+(LT*RT)%mod)%mod ;
            }
        } 
    }

    return dp[i][j][isTrue] = ways; 
}
/*
Time Complexity: O(N*N*2 * N) ~ O(N3) There are a total of 2*N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

Space Complexity: O(2*N2), 2*N2 for the dp array we are using.
*/
ll tabulation(string & exp){ 
    int n = exp.size()  ; 
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,0))) ; 
    //BASE CASE (i==j) 
    for(int i=0;i<n;i++){
        dp[i][i][0] =  exp[i]=='F' ; 
        dp[i][i][1] =  exp[i]=='T' ; 
    }

    for(int i=n-1;i>=0;i--){ 
        // as i<j && i==j -> base case 
        for(int j=i+1;j<n;j++){
              for(int isTrue=0;isTrue<=1;isTrue++){
                    ll ways = 0 ; 
            //from i+1 as when i=0 at i=1 we have operand and than at every 2 distnace 
                for(int ind = i+1 ; ind<=j-1;ind+=2){
                    ll LT = dp[i][ind-1][1] ; 
                    ll LF = dp[i][ind-1][0]  ; 
                    ll RT = dp[ind+1][j][1]  ; 
                    ll RF = dp[ind+1][j][0]  ; 

                    //see all operands now 
                    if(exp[ind]=='&'){
                        if(isTrue){
                            ways= (ways+(LT*RT)%mod)%mod; 
                        }
                        else{
                            ways=(ways+(LF*RF)%mod+(LF*RT)%mod+(LT*RF)%mod)%mod;
                        }
                    }   
                    else if(exp[ind]=='|'){
                        if(isTrue){
                            ways= (ways+(LT*RT)%mod+ (LF*RT)%mod + (LT*RF)%mod )%mod ; 
                        }
                        else{
                            ways=(ways+(LF*RF)%mod)%mod ;
                        }
                    } 
                    else if(exp[ind]=='^'){
                        if(isTrue){
                            ways=( ways+ (LF*RT)%mod + (LT*RF)%mod )%mod ; 
                        }
                        else{
                            ways=( ways+ (LF*RF)%mod+(LT*RT)%mod)%mod ;
                        }
                    } 
                }
                   dp[i][j][isTrue] = ways; 
              }
        }
    }
    return dp[0][n-1][1] ;
}
int evaluateExp(string & exp) {
     int n = exp.size()  ; 
     vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1))) ; 

   //  return f(0,n-1,1,exp,dp);
    return tabulation(exp) ;

}
