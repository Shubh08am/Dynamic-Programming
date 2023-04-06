 #include <bits/stdc++.h>
 int solve(int day,int last,vector<vector<int>> &points){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int pt = points[day][i] + solve(day-1,i,points);
                maxi=max(maxi,pt);
            }
        }
        return maxi;
}
int solve2(int day,int last,vector<vector<int>> &points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last] ; 

    int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int pt = points[day][i] + solve2(day-1,i,points,dp);
                maxi=max(maxi,pt);
            }
        }
        return dp[day][last]=maxi;
}
int tabulation(int n,vector<vector<int>> &points){
 vector<vector<int>>dp(n, vector<int>(4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }
  return dp[n - 1][3];
}
int tabulationWithSpaceOptimization(int n,vector<vector<int>> &points){
  vector<int>prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max({points[0][0],points[0][1], points[0][2]});

  for (int day = 1; day < n; day++) {
      vector<int>curr(4, 0);
    for (int last = 0; last < 4; last++) {
      curr[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + prev[task];
          curr[last] = max(curr[last], activity);
        }
      }
     }
     prev=curr;
  }
  return prev[3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // return solve(n-1,3,points);
   // vector<vector<int>>dp(n,vector<int>(4,-1));
   // return solve2(n-1,3,points,dp);
   //  return tabulation(n,points); 
     return tabulationWithSpaceOptimization(n,points);
}
