#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int N,M,S,weight[105],id,K,num;
vector<int> V[105];
vector<vector<int> > ans;
void DFS(int pos,int sum,vector<int>& temp){
    sum+=weight[pos];
    temp.push_back(weight[pos]);
    if(sum>=S){
        if(sum==S&&V[pos].size()==0)ans.push_back(temp);
        sum-=weight[pos];
        temp.pop_back();
        return;
    }
    for(int i=0;i<V[pos].size();i++){
        DFS(V[pos][i],sum,temp);
    }
    sum-=weight[pos];
    temp.pop_back();
}
bool cmp(int a,int b){
    return weight[a]>weight[b];
}
int main(){
    cin>>N>>M>>S;
    for(int i=0;i<N;i++)cin>>weight[i];
    for(int i=0;i<M;i++){
        cin>>id>>K;
        for(int i=0;i<K;i++){
            cin>>num;
            V[id].push_back(num);
        }
        sort(V[id].begin(),V[id].end(),cmp);
    }
    vector<int> temp;
    DFS(0,0,temp);
    sort(ans.begin(),ans.end(),greater<vector<int> >());
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1)cout<<' ';
            else cout<<endl;
        }
    }
}