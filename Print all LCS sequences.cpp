class Solution{
	public:
	unordered_set<string>st;
	void printAllLCS(int i,int j,string &s, string &t,string &dummy, vector<string> &answer, int lenOfLcs){
	     int n = s.size(),m=t.size(); 
	     
	    //base case 
	    if(lenOfLcs==0){
	        //take unique LCS only 
	        if(st.find(dummy)==st.end()){
	            st.insert(dummy);
	            answer.push_back(dummy);
	        }
	        return;
	    }
	    
	    if(i>=n || j>=m) return ;
	    
	    //otherwise take all LCS using back-tracking logic 
	    for(int si=i;si<n;si++){
	        for(int tj=j;tj<m;tj++){
	            if(s[si]==t[tj]){
	                dummy+=s[si];
	                //go to diagonal position now
	                printAllLCS(si+1,tj+1,s,t,dummy,answer,lenOfLcs-1);
	                //back-tracking 
	                dummy.pop_back();
	            }
	        }
	    }
	    
	}
		vector<string> all_longest_common_subsequences(string s, string t){
		     int n = s.size(),m=t.size(); 
    vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ; 
    
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
    
     int lenOfLcs = dp[n][m] ; 
 
     vector<string>answer;
     string dummy = "" ; 
     printAllLCS(0,0,s,t,dummy,answer,lenOfLcs) ;
     sort(answer.begin(),answer.end()) ;
     return answer;
		}
};
