#include<bits/stdc++.h>
using namespace std;

 //Printing the LIS :- Time Complexity: O(N*N)+O(LENGTH OF LIS) [FOR BACTRACKING] Space Complexity: O(N)
void printLIS(int n,vector<int>&nums){
vector<int>dp(n,1) , hash(n) ; 
//dp gives length of LIS 
//hash is used to backtrack and print LIS by storing prev index of elements

    for(int ind=0;ind<n;ind++){
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[ind]>nums[prev_ind] && dp[ind]<1+dp[prev_ind]){
                    dp[ind]=1+dp[prev_ind];
                    hash[ind]=prev_ind;
            }
        }
    }

    int lenOfLIS = 1 , lastIndex=0; //store the index of last element of lis and start from it  
    for(int i=0;i<n;i++){
        if(lenOfLIS<dp[i]){
            lenOfLIS=dp[i];
            lastIndex=i;
        }
    }
    //storing from last element to first so at last reverse it 
    vector<int>lisorder;
    lisorder.push_back(nums[lastIndex]) ; 
    
    //Now,backtrack using hash 
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        lisorder.push_back(nums[lastIndex]) ;
    }
    //reverse now 
    reverse(lisorder.begin(),lisorder.end());

  cout<< "LENGTH OF LIS " << lenOfLIS << "\n" ; 

  cout<< "PRINTING LIS\n";
for(auto it : lisorder) cout<< it << " ";
}
int main(){
    int n;cin>>n;
    vector<int>nums(n); 
    for(int i=0;i<n;i++) cin>>nums[i] ; 

    printLIS(n,nums) ; 
}
