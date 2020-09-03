//dynamic programming


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//package question

//basic package
//time complexity O(nv),space complexity O(nv),n is the number of items, v is the size of package
int basicPack(vector<int>&weight,vector<int>&cost,int cap){
    int n=weight.size();
    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int i=1;i<=n;++i){
        for(int j=weight[i];j<=cap;++j){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+cost[i]);
        }
    }
    return dp[n][cap];
}
//basic package with space improvement
//time complexity O(nv),space complexity O(v),n is the number of items, v is the size of package
int basicPackWithSpaceImprovement(vector<int>&weight,vector<int>&cost,int cap){
    int n=weight.size();
    vector<int>dp(cap+1,0);
    for(int i=1;i<=n;++i){
        for(int j=cap;j>=weight[i];--j){
            dp[j]=max(dp[j],dp[j-weight[i]]+cost[i]);
        }
    }
    return dp[cap];
}

int main(){

    return 0;
}
