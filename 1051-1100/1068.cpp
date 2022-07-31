//15:18 - 15:38 - 29分
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,num[10005],sum=0,flag=0;
bool vis[10005];
vector<int> ans;

void DFS(int s){
    if(flag)return;
    if(s==M){
        flag=1;
        return ;
    }
    for(int i=0;i<N;i++){
        if(!vis[i]){
            if(sum+num[i]>M)break;
            else{
                sum+=num[i];
                vis[i]=true;
                ans.push_back(num[i]);
                DFS(sum);
                if(flag)return;
                ans.pop_back();
                vis[i]=false;
                sum-=num[i];
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num[i];
        vis[i]=false;
    }
    sort(num,num+N);
    DFS(sum);
    if(ans.size()==0){
        cout<<"No Solution";
    }
    else{
        for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
    }
    }
    
}
