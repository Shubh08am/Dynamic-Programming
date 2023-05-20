class Solution {

public:

    bool isPalindrome(int start,int end,string &s){

         int n = s.size() ; 

        while(start<end){

            if(s[start++]!=s[end--]) return false;

        }

        return true;

    }

     //Approach-1 Recursion Time Complexity: EXPONENTIAL

    int solve(int i,string &s){

         int n = s.size() ; 

        if(i==n) return 0;

        int reqPal=1e9;

        for(int ind=i;ind<n;ind++){

            if(isPalindrome(i,ind,s)){

               int pal=1+solve(ind+1,s); //only right sub-problem left to solve as left one gives palindrome sub-string

               reqPal = min(reqPal,pal);

            }

        }

    return reqPal;

    }

     //Approach-1 Recursion Time Complexity: EXPONENTIAL

    int solve7(int i,string &s){

         int n = s.size() ; 

         if(i>=n-1 || isPalindrome(i,n-1,s)) return 0;

        int reqPal=1e9;

        for(int ind=i;ind<n;ind++){

            if(isPalindrome(i,ind,s)){

               int pal=1+solve7(ind+1,s); //only right sub-problem left to solve as left one gives palindrome sub-string

               reqPal = min(reqPal,pal);

            }

        }

    return reqPal;

    }

     //Approach-1 Recursion Time Complexity: EXPONENTIAL

      int solve3(int i,int j,string &s){

         if(isPalindrome(i,j,s)) return 0;

        int reqPal=1e9;

        for(int ind=i+1;ind<=j;ind++){

                int pal=1+solve3(i,ind-1,s) + solve3(ind,j,s);  

               reqPal = min(reqPal,pal);

         }

    return reqPal;

    }

    

    //Approach-2 Memoization :- 

    int solve5(int i,int j,string &s, vector<vector<int>>&dp){

         if(isPalindrome(i,j,s)) return 0;

         if(dp[i][j]!=-1) return dp[i][j];

        int reqPal=1e9;

        for(int ind=i+1;ind<=j;ind++){

                int pal=1+solve5(i,ind-1,s,dp) + solve5(ind,j,s,dp);  

               reqPal = min(reqPal,pal);

         }

    return dp[i][j]=reqPal;

    }

    //Approach-1 Recursion Time Complexity: EXPONENTIAL

     int solve4(int i,int j,string &s){

         if(i>=j || isPalindrome(i,j,s)) return 0;

        int reqPal=1e9;

        for(int ind=i;ind<=j;ind++){

               if(isPalindrome(i,ind,s)){

                   /*

                        We will recurse for only right part

                        Only when left part turns out to be palindrome

                        

                        Reason : If left substring becomes palindrome then there is no need to partition it further 

                        (which in turn reduces the number of recursive calls)

                   */

                int pal=1+solve4(ind+1,j,s);  

                 reqPal = min(reqPal,pal);

             }

         }

    return reqPal;

    }

    //Approach-2 Memoization :- 

    int solve6(int i,int j,string &s,vector<int>&dp){

         if(i>=j || isPalindrome(i,j,s)) return 0;

        if(dp[i]!=-1) return dp[i];

        int reqPal=1e9;

        for(int ind=i;ind<=j;ind++){

               if(isPalindrome(i,ind,s)){

                   /*

                        We will recurse for only right part

                        Only when left part turns out to be palindrome

                        

                        Reason : If left substring becomes palindrome then there is no need to partition it further 

                        (which in turn reduces the number of recursive calls)

                   */

                int pal=1+solve6(ind+1,j,s,dp);  

                 reqPal = min(reqPal,pal);

             }

         }

    return dp[i]=reqPal;

    }

    //Approach-2 Memoization :- 

    int solve2(int i,string &s, vector<int>&dp){

         int n = s.size() ; 

        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int reqPal=1e9;

        for(int ind=i;ind<n;ind++){

            if(isPalindrome(i,ind,s)){

               int pal=1+solve2(ind+1,s,dp); //only right sub-problem left to solve as left one gives palindrome sub-string

               reqPal = min(reqPal,pal);

            }

        }

    return dp[i]=reqPal;

    }

    //Approach-2 Memoization :- 

    int solve8(int i,string &s, vector<int>&dp){

         int n = s.size() ; 

         if(isPalindrome(i,n-1,s)) return 0;

        if(dp[i]!=-1) return dp[i];

        int reqPal=1e9;

        for(int ind=i;ind<n;ind++){

            if(isPalindrome(i,ind,s)){

               int pal=1+solve8(ind+1,s,dp); //only right sub-problem left to solve as left one gives palindrome sub-string

               reqPal = min(reqPal,pal);

            }

        }

    return dp[i]=reqPal;

    }

    int minCut(string s) {

        int n = s.size() ; 

      //  return solve(0,s)-1 ; 

     //     return solve7(0,s);

     //    return solve3(0,n-1,s) ; 

      

      //    vector<vector<int>>dp(n,vector(n,-1));

      //  return solve5(0,n-1,s,dp);

     //    return solve4(0,n-1,s) ;

       

       //     vector<int>dp(n,-1);

      //   return solve6(0,n-1,s,dp);

     //   vector<int>dp(n,-1);

     //   return solve2(0,s,dp)-1;

      vector<int>dp(n,-1);

       return solve8(0,s,dp);

    }

};
