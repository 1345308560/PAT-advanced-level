#include<iostream>
#include<vector>
#include<set>
using namespace std;
int mp[1005][1005]={},S2[1005]={};
set<int> S[1005];
int K,N,M,num1,num2,dur;
bool vis[1005]={};
vector<int> Vs;
int call[1005]={},call_back[1005]={};
void DFS(int n,vector<int>& t){
    t.push_back(n);
    vis[n]=true;
    for(int j=n+1;j<Vs.size();j++){
        if(!vis[j])
            if(mp[Vs[n]][Vs[j]]&&mp[Vs[j]][Vs[n]])
                DFS(j,t);
    }
}
int main(){
    cin>>K>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2>>dur;
        mp[num1][num2]+=dur;
        // if(mp[num1][num2]<=5)S[num1].insert(num2);
        // else S[num1].erase(num2);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            if(mp[i][j]&&mp[i][j]<=5)S[i].insert(j);
    }
    for(int i=1;i<=N;i++){
        if(S[i].size()>K){
            for(auto j:S[i]){
                if(mp[j][i]>0)S2[i]++;
            }
            if(S2[i]*5<=S[i].size())Vs.push_back(i);
        }
    }
    if(Vs.size()==0){
        cout<<"None";
        return 0;
    }
    for(int i=0;i<Vs.size();i++){
        vector<int> temp;
        if(!vis[i]){
            DFS(i,temp);
            for(int j=0;j<temp.size();j++){
                cout<<Vs[temp[j]];
                if(j<temp.size()-1)cout<<' ';
                else cout<<endl;
            }
        }
    }
}