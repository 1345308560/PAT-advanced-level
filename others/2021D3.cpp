#include<iostream>
#include<vector>
using namespace std;
int N,M,n,num,s[100005]={};
vector<int> V[100005];
int check(int x){
    if(s[x]!=-1)return s[x];
    if(V[x].size()==0){
        s[x]=1;
        return s[x];
    }
    else{
        int ans=1;
        for(int i=0;i<V[x].size();i++)
            ans+=check(V[x][i]);
        s[x]=ans;
        return s[x];
    }
}
int main(){
    cin>>N;
    for(int i=2;i<=N;i++){
        cin>>num;
        V[num].push_back(i);
    }
    fill(s,s+N+1,-1);
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>n;
        cout<<check(n)<<endl;
    }
}