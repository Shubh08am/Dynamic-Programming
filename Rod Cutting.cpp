problem link gfg :- https://practice.geeksforgeeks.org/problems/rod-cutting0840/1 
 
class Solution{
  public:
//Approach-1 Recursion Time Complexity: O(2^N)[Exponential] [greater than it as we stay at ind after take operation] 
// Space Complexity: O(N) [In worst case] and not O(N) [as we stay at ind after take operation]
int solve(int ind,int N, int price[]){
    //NOTE:- RECURSION CALL FROM (N-1,N) only possible 

     if(ind==0){     
        //Taking rodLength of 1 N times gives total length as N
        //total prices will be N*price[0] 
        return N*price[0];
    }
    int notTake = solve(ind-1,N,price) ; 
    int take = INT_MIN;
    //at any index rod length is given as follow:-
    int RodLength = ind+1;
     //stay at ind position only as we may use it again on reduced target :- INFINITE SUPPLY
     //if available RodLength is smaller than or equal to Given rod length 
     //than only take possible
    if(RodLength<=N) take = price[ind]+solve(ind,N-RodLength,price);
    return max(take,notTake);
}
//Approach-2 Memoization Time Complexity: O(N*N) , Space Complexity: O(N*N) + O(W)
int solve2(int ind,int N,int price[],vector<vector<int>>&dp){
      if(ind==0){     
         //Taking rodLength of 1 N times gives total length as N
        //total prices will be N*price[0] 
        return N*price[0];
    }
    if(dp[ind][N]!=-1) return dp[ind][N];

    int notTake = solve2(ind-1,N,price,dp) ; 
    int take = INT_MIN;
    //at any index rod length is given as follow:-
    int RodLength = ind+1;
    
     //stay at ind position only as we may use it again on reduced target :- INFINITE SUPPLY
     //if available RodLength is smaller than or equal to Given rod length 
     //than only take possible

    if(RodLength<=N) take = price[ind]+solve2(ind,N-RodLength,price,dp);
    return dp[ind][N]=max(take,notTake);
}
//Approach-3 Tabulation Time Complexity: O(N*W) , Space Complexity: O(N*W)
int tabulation(int N, int price[]){
     vector<vector<int>>dp(N,vector<int>(N+1,0));
  //Recursion call from(n-1,n) i.e tabulation from ind = 0
  //(base-case [bottom]) to n-1([Up]) & N = 0 to N

    //for ind=0 base case :- N varies from 0 to N
    for(int rodLen=0;rodLen<=N;rodLen++){
        //Taking rodLength of 1 N times gives total length as N
        //total prices will be N*price[0] 
        dp[0][rodLen] = rodLen*price[0];
    }
    
    //for ind=0 done start from ind=1
    for(int ind=1;ind<N;ind++){
        for(int rodLen=0;rodLen<=N;rodLen++){
            //NOTE:- ALWAYS TAKE NESTED LOOP PARAMETER IN DP STATES
            //NOT ORIGINAL ONE(DID THIS MISTAKE MANY TIMES)
            int notTake = dp[ind-1][rodLen];
            int take = INT_MIN;
            //at any index rod length is given as follow:-
            int RodLength=ind+1;
    //stay at ind position only as we may use it again on reduced target :- INFINITE SUPPLY
     //if available RodLength is smaller than or equal to Given rod length 
     //than only take possible
            if(RodLength<=rodLen) take = price[ind]+dp[ind][rodLen-RodLength];
            
             dp[ind][rodLen]=max(take,notTake);
        }
    }
    return dp[N-1][N];//as Recursion call from(n-1,n)
}
int tabulationWithSpaceOptimization(int N, int price[]){
     vector<int>prev(N+1,0),curr(N+1,0);


    //for ind=0 base case :- N varies from 0 to N
    for(int rodLen=0;rodLen<=N;rodLen++){
        //Taking rodLength of 1 N times gives total length as N
        //total prices will be N*price[0] 
        prev[rodLen] = rodLen*price[0];
    }
    
    //for ind=0 done start from ind=1
    for(int ind=1;ind<N;ind++){
        for(int rodLen=0;rodLen<=N;rodLen++){
            int notTake = prev[rodLen];
            int take = INT_MIN;
            int RodLength=ind+1;
    //stay at ind position only as we may use it again on reduced target :- INFINITE SUPPLY
     //if available RodLength is smaller than or equal to Given rod length 
     //than only take possible
            if(RodLength<=rodLen) take = price[ind]+curr[rodLen-RodLength];
            
             curr[rodLen]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[N]; 
}

int tabulationWithSpaceOptimization2(int N, int price[]){
     vector<int>prev(N+1,0);


    //for ind=0 base case :- N varies from 0 to N
    for(int rodLen=0;rodLen<=N;rodLen++){
        //Taking rodLength of 1 N times gives total length as N
        //total prices will be N*price[0] 
        prev[rodLen] = rodLen*price[0];
    }
    
    //for ind=0 done start from ind=1
    for(int ind=1;ind<N;ind++){
        for(int rodLen=0;rodLen<=N;rodLen++){
            int notTake = prev[rodLen];
            int take = INT_MIN;
            int RodLength=ind+1;
      //stay at ind position only as we may use it again on reduced target :- INFINITE SUPPLY
     //if available RodLength is smaller than or equal to Given rod length 
     //than only take possible
            if(RodLength<=rodLen) take = price[ind]+prev[rodLen-RodLength];
            
             prev[rodLen]=max(take,notTake);
        }
     }
    return prev[N]; 
}
    int cutRod(int price[], int n) {
    //  return solve(n-1,n,price); 

   // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //return solve2(n-1,n,price,dp);//Approach-2 Memoization

  // return tabulation(n,price);//Approach-3 Tabulation
   
   //return tabulationWithSpaceOptimization(n,price);//Approach-4 tabulationWithSpaceOptimization[Two array Used]
  return tabulationWithSpaceOptimization2(n,price); ////Approach-5 tabulationWithSpaceOptimization[Single array Used]
    }
};
