//problem link:- https://practice.geeksforgeeks.org/problems/coin-change2448/1 
class Solution {
  public:
 //Approach-1 Recursion Time Complexity: O(2^N) [greater than it as we stay at ind after take operation] 
    // Space Complexity: O(amount) [In worst case] and not O(N) [as we stay at ind after take operation]
    long solve(int ind,int coins[], int amount,int n){
          //when amount exhausted 
           if(ind==n-1){
              //if by using that last coin amount can be exhausted 
              //its possible therefore return 1 else not Possible
              return (amount%coins[n-1]==0) ;
          }
          //Explore all the ways 
          long take=0;
          long  notTake = solve(ind+1,coins,amount,n) ; 
          //stay at ind position only as we may use it again on reduced target
              if(coins[ind]<=amount) take = solve(ind,coins,amount-coins[ind],n) ; 
           return take+notTake ;
    }
     //Approach-2 Memoization :- Time Complexity: O(N*amount) Space Complexity: O(N*amount) + O(amount)
    long long int solve2(int ind,int coins[], int amount,vector<vector<long long int>>&dp,int n){
           //when amount exhausted 
           if(ind==n-1){
             //if by using that last coin amount can be exhausted 
              //its possible therefore return 1 else not Possible
              return (amount%coins[n-1]==0) ;
          } 
            if(dp[ind][amount]!=-1)  return dp[ind][amount] ; 
          //Explore all the ways 
          long take=0;
          long notTake = solve2(ind+1,coins,amount,dp,n) ; 
         //stay at ind position only as we may use it again on reduced target
          //INFINITE SUPPLY LOGIC :- STAY  AT SAME INDEX
              if(coins[ind]<=amount) take = solve2(ind,coins,amount-coins[ind],dp,n) ; 
           return dp[ind][amount] = take+notTake;
    }
     //Approach-3 Tabulation :- Time Complexity: O(N*amount) Space Complexity: O(N*amount)
    long tabulation(int coins[], int amount,int n){
          vector<vector<long>>dp(n,vector<long>(amount+1,0));
         //Recursion call from(0,amount) i.e tabulation from ind = n-1(base-case [bottom]) to 0([Up]) & target = 0 to target

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             dp[n-1][tar] =(tar%coins[n-1]==0);
          }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    long notTake = dp[ind+1][tar] ;
                    long take = 0 ; 
                     //stay at ind position only as we may use it again on reduced target
                    if(coins[ind]<=tar) take =dp[ind][tar-coins[ind]] ; 

                    dp[ind][tar] = take+notTake ;
             }
        }
        return dp[0][amount] ;//as Recursion call from(0,amount)
    }
     //Approach-4 Tabulation with Space Optimization  :- Time Complexity: O(N*amount) Space Complexity: O(amount)
    long tabulationWithSpaceOptimization(int coins[], int amount,int n){
          vector<long>prev(amount+1,0),curr(amount+1,0);

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             prev[tar] = (tar%coins[n-1]==0);
          }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= 0; tar<=amount;tar++){
                    long notTake = prev[tar] ;
                    long take = 0 ; 
                     //stay at ind position only as we may use it again on reduced target
                    //since,at position=ind we use curr and not prev
                    if(coins[ind]<=tar) take =curr[tar-coins[ind]] ; 

                    curr[tar] = take+notTake;
             }
             prev=curr;
        }
        return prev[amount] ;
    }
//Approach-5 Tabulation with Space Optimization[Using Single Array]  :- Time Complexity: O(N*amount) Space Complexity: O(amount)
    long tabulationWithSpaceOptimization2(int coins[], int amount,int n){
          vector<long>prev(amount+1,0);

         //for ind=n-1 base case :- amount varies from 0 to amount
         for(int tar=0;tar<=amount;tar++){
             prev[tar] =(tar%coins[n-1]==0);
          }

         //for ind=n-1 done start from ind=n-2 
         for(int ind=n-2;ind>=0;ind--){
             for(int tar= amount; tar>=0;tar--){
                    long notTake = prev[tar] ;
                    long take = 0 ; 
                     //stay at ind position only as we may use it again on reduced target
                     
                    if(coins[ind]<=tar) take = prev[tar-coins[ind]] ; 
               
               //overwrite curr value in prev as for calculating curr[ind] 
               //we don't need left guy of prev[ind] only same column guy of curr[ind] i.e prev[ind]
               //thus,all left value from prev[ind] is not used therefore we can directly update
                    prev[tar] =  take+notTake;
             }
        }
        return prev[amount] ;
    }
    long long int count(int coins[], int n, int amount) {

       
       
      // long long int coin = solve(0,coins,amount,n) ;
      // return coin ; //Approach-1 Recursion

       // vector<vector<long long int>>dp(n,vector<long long int>(amount+1,-1));
       //long long int coin2 = solve2(0,coins,amount,dp,n);
       //return coin2 ; //Approach-2 Memoization
   
     //long long int coin3 = tabulation(coins,amount,n);
      // return coin3 ; //Approach-3 Tabulation

     //  long long int coin4 = tabulationWithSpaceOptimization(coins,amount,n);
     // return coin4 ; //Approach-4 tabulationWithSpaceOptimization

      long long int coin5 = tabulationWithSpaceOptimization(coins,amount,n);
      return coin5 ; //Approach-5 tabulationWithSpaceOptimization[Single array Used]
    }
};
