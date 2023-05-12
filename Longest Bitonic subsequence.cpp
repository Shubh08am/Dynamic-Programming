class Solution{
	public:
//Time Complexity:	O(N*N)[LIS FROM FRONT]+O(N*N)[LIS FROM BACK]+O(N)[for BITONIC] 
//Space Complexity: O(2*N)
	int LongestBitonicSequence(vector<int>nums){
	    //FIND LIS FROM FRONT AND LIS FROM BACK 

	    int n=nums.size();
	    // Length of lis can always be 1 include single elements only therefore initialized to 1 
	    
	    //FINDING LIS FROM FRONT
	     vector<int>dp(n,1); 
         for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind]>nums[prev_ind] && 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                }
            }
         }
         
          //FINDING LIS FROM BACK
         vector<int>dp2(n,1); 
          for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=n-1;prev_ind>ind;prev_ind--){
                if(nums[ind]>nums[prev_ind] && 1+dp2[prev_ind]>dp2[ind]){
                    dp2[ind]=1+dp2[prev_ind];
                }
            }
         }
        
        //NOW, FOR BITONIC FOR ANY ELEMENT LIS FROM FRONT + LIS FROM BACK - 1 SHOULD BE MAX 
        //i.e dp[i]+dp2[i]-1 [-1 because ith element is involved twice in lis from front and lis from back]
        // therefore consider ith element once only 
        int Bitonic=1;
        for(int i=0;i<n;i++){
            Bitonic =max(Bitonic,dp[i]+dp2[i]-1);
        } 
        return Bitonic;
	}
};
