//dynamic programming


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//Package Questions

//basic package(01 package)
//time complexity O(nv),space complexity O(nv),n is the number of items, v is the size of package
int basicPack(vector<int>&weight,vector<int>&cost,int cap){
    int n=weight.size();
    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int i=1;i<=n;++i){
        for(int j=weight[i];j<=cap;++j){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+cost[i-1]);
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
            dp[j]=max(dp[j],dp[j-weight[i-1]]+cost[i-1]);
        }
    }
    return dp[cap];
}
//trick for the initialization : if we needs to exactly fill the bag with v capacity we should initialize the
//v[0]=0 and the others are INT_MIN, cause for others they are invalid, if we don't need to fill all capacity
//we can initialize all elements into 0

//a little improvement for the lower bound of inner cycle ,j>=weight[i]->j>=max(weight[i],V-key)
//key = sum of weight[i] to weight[n]

//complete package (all items with infinite num)
int completePackage(vector<int>&weight,vector<int>&cost,int cap){
    int n=weight.size();
    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=cap;++j){
            for(int k=1;k<=j/weight[i-1];++k){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*weight[i-1]]+k*cost[i-1]);
            }
        }
    }
    return dp[n][cap];
}
//basic improvement
int completePackageWithImprovement(vector<int>&weight,vector<int>&cost,int cap){
    //delete all items whose cj<ci while weightj>weight i
    //notice that if the weight of item is larger than cap we can not
    //use it as a principle
    int n=weight.size();
    set<int>se;
    for(int i=0;i<n;++i) {
        if (se.count(i) || weight[i] > cap)continue;
        for (int j = 0; j < n; ++j) {
            if (se.count(j) || i == j || weight[j] > cap)continue;
            if (weight[i] < weight[j] && cost[i] > cost[j])se.insert(j);
        }
    }
    vector<int>tmp;
    for(int i=0;i<n;++i){
        if(se.count(i))continue;
        tmp.push_back(weight[i]);
    }
    weight=tmp;
    tmp.clear();
    for(int i=0;i<n;++i){
        if(se.count(i))continue;
        tmp.push_back(cost[i]);
    }
    cost=tmp;//we complete the first stage improvement of original weight and cost array


    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=cap;++j){
            for(int k=1;k<=j/weight[i-1];++k){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*weight[i-1]]+k*cost[i-1]);
            }
        }
    }
    return dp[n][cap];
}
int main(){

    return 0;
}
