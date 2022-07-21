// 16：41 - 17:01 - 24分
// 膜拜柳神  17：18 - 30分
#include<iostream>
#include<vector>
using namespace std;
int N,N1,N2,vis[205]={},dp[10005]={},MAX=0;
vector<int> n;
int main(){
    cin>>N>>N1;
    for(int i=1;i<=N1;i++){
        int num;
        cin>>num;
        vis[num]=i;
    }
    cin>>N2;
    for(int i=0;i<N2;i++){
        int num;
        cin>>num;
        if(vis[num])n.push_back(vis[num]);
    }
    for(int i=0;i<n.size();i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(n[i]>=n[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        MAX=max(MAX,dp[i]);
    }
    cout<<MAX;
}
