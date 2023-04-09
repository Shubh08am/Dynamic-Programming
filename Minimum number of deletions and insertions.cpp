class Solution{
	public:
  //Approach-1 Recursion 
		int f1(string s1,string s2,int i,int j){
	    if(i==0 || j==0) return 0;
	    

	    if(s1[i-1]==s2[j-1]){
	        return 1 + f1(s1,s2,i-1,j-1) ;
	    }
	    
	    return max(f1(s1,s2,i-1,j) , f1(s1,s2,i,j-1));
	}
	
	//Approach-2 Memoization
	int f(string s1,string s2,int i,int j,vector<vector<int>>&dp){
	    if(i==0 || j==0) return 0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    if(s1[i-1]==s2[j-1]){
	        return dp[i][j] = 1 + f(s1,s2,i-1,j-1,dp) ;
	    }
	    
	    return dp[i][j] = max(f(s1,s2,i-1,j,dp) , f(s1,s2,i,j-1,dp));
	}
//Approach-3 tabulation
	int tabulation(string &str1, string &str2){
    	     int n = str1.size() , m = str2.size();
	     vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ; 
	     
	     for(int i=1;i<=n;i++){
	         for(int j=1;j<=m;j++){
	             if(str1[i-1]==str2[j-1]){
	                 dp[i][j] = 1 + dp[i-1][j-1];
	             }
	             else{
	                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	             }
	         }
	     }
	     
	     int lenOfLCS = dp[n][m] ;
	     int deletionOper = n ;
	     int insertionOper = m ; 
	     int totalOper = n+m-2*lenOfLCS;
	     return totalOper;
}

   //Approach-4 tabulation With Space Optimization
	int tabulationWithSpaceOptimization(string &str1, string &str2){
    	     int n = str1.size() , m = str2.size();
	      vector<int>prev(m+1,0) , curr(m+1,0) ; 
	     
	     for(int i=1;i<=n;i++){
	         for(int j=1;j<=m;j++){
	             if(str1[i-1]==str2[j-1]){
	                 curr[j] = 1 + prev[j-1];
	             }
	             else{
	                 curr[j] = max(prev[j],curr[j-1]);
	             }
	         }
	         prev=curr;
	     }
	     
	     int lenOfLCS = prev[m] ;
	     int deletionOper = n ;
	     int insertionOper = m ; 
	     int totalOper = n+m-2*lenOfLCS;
	     return totalOper;
}
   //Approach-4 tabulation With Space Optimization [Using single array]
	int tabulationWithSpaceOptimization2(string &str1, string &str2){
    	     int n = str1.size() , m = str2.size();
	      vector<int>prev(m+1,0) ; 
	     
	     for(int i=1;i<=n;i++){
	         int curr = prev[0] ; 
	         for(int j=1;j<=m;j++){ 
	             int temp = prev[j];
	             if(str1[i-1]==str2[j-1]){
	                 prev[j] = 1 + curr; //prev[j-1] indicated by curr
	             }
	             else{
	                 prev[j] = max(prev[j],prev[j-1]);
	             }
	             curr=temp;
	         }
 	     }
	     
	     int lenOfLCS = prev[m] ;
	     int deletionOper = n ;
	     int insertionOper = m ; 
	     int totalOper = n+m-2*lenOfLCS;
	     return totalOper;
}
	int minOperations(string str1, string str2) { 
	     int n = str1.size() , m = str2.size();
	     vector<vector<int>>dp(n+1,vector<int>(m+1,-1)) ; 
	  
	      int lenOfLCS = f1(str1,str2,n,m) ; //for Recursion
	    //  int lenOfLCS = f(str1,str2,n,m,dp) ; //for Memoization
	     int deletionOper = n - lenOfLCS;
	     int insertionOper = m - lenOfLCS ; 
	     int totalOper = deletionOper + insertionOper  ;
	     
	      // return totalOper; //for Recursion 
	    
	    // return totalOper; //for Memoization 
	    
	   // return tabulation(str1,str2) ;
	    
	   // return tabulationWithSpaceOptimization(str1,str2) ; //tabulationWithSpaceOptimization
	    
	    return tabulationWithSpaceOptimization2(str1,str2) ; //tabulationWithSpaceOptimization
	} 
};   
  
