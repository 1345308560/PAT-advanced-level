// 23:45 - 23:56 - 25分
#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int N,M,K,num1,num2,n,num[5005];
vector<int> V[1005],ans;
map<int,int> Mp;
bool check(){
    int degree[1005];
    for(int i=1;i<=N;i++)degree[i]=Mp[i];
    for(int i=0;i<N;i++){
        if(degree[num[i]]!=0)return true;
        for(int j=0;j<V[num[i]].size();j++)
            degree[V[num[i]][j]]--;
    }
    return false;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        V[num1].push_back(num2);
        Mp[num2]++;
    }
    cin>>K;
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++)cin>>num[j];
        if(check())ans.push_back(i);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
    }
}