#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*M) + O(N+M)  Space Complexity: O(N*M)
//Using Tabulation Logic :- Recursion cll from (n,m)
void lcs(string s , string t){
  int n = s.size(),m=t.size(); 
    vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ; 
    
    //T.C:- O(N*M) [For nested loops]
    for(int i=0;i<=n;i++) dp[i][0] = 0 ; //for j=0 , i varies from 0 to n
    for(int j=0;j<=m;j++) dp[0][j] = 0 ; //for i=0 , j varies from 0 to m

    //for i=1 & j=1 onwards
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){ //match case
                    dp[i][j]  = 1 + dp[i-1][j-1];
                }
                else{ //Not-match case
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]) ;
                }
        }
    }
    
    // T.C :-  O(N+M) [Backtracking Logic]
    int lenOfLcs = dp[n][m] ; 
    string answer(lenOfLcs,'#') ; //answer for LCS string 

    int i=n,j=m ;
    int index = lenOfLcs-1;

    //till string s or t get exhausted (i.e either i==0 || j==0) 
    while(i>0 && j>0){
        //match case 
        if(s[i-1]==t[j-1]){ 
                answer[index] = s[i-1] ;  //put string in index position
                index--; //go to prev pos to put string next time 
                i--;j--; //as diagonal movement when match case  dp[i][j]  = 1 + dp[i-1][j-1];
        }
       //Not-match case  
        else{ //when equal we can go to any case 1 or case 2 our wish :- here going to case 2
                if( dp[i-1][j] > dp[i][j-1] ) {
                    //move from (i,j) to (i-1,j) 
                    i--;
                }
                else if( dp[i-1][j] <= dp[i][j-1] ) {
                    //move from (i,j) to (i,j-1) 
                    j--;
                }
        }
    }
    cout<<answer<<"\n" ;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout << "The Longest Common Subsequence is ";
     lcs(s, t);


    return 0;
}
