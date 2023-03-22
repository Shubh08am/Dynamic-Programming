class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int nums[], int n)
    {
        int prev=nums[0] , prev2=0;
        for(int i=1;i<n;i++){
           int pick = nums[i] ; 
           if(i>1) pick+=prev2 ;  //from recurrence relation
           int notpick = 0+prev;
           int curri = max(pick,notpick);
           prev2=prev;
           prev=curri;
       }
       return prev;
    }
};
