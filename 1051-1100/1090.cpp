//17:42 - 17:56 - 25分
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int N,f[100005],level[100005],root=-1,ans1=0,ans2=0;
double P,r;
bool vis[100005]={};
void DFS(int id){
    vis[id]=true;
    if(id==root)level[id]=0;
    else{
        if(!vis[f[id]])DFS(f[id]);
        level[id]=level[f[id]]+1;
    }
    if(level[id]>ans1){
        ans1=level[id];
        ans2=1;
    }
    else if(level[id]==ans1)ans2++;
}
int main(){
    cin>>N>>P>>r;
    r/=100;
    for(int i=0;i<N;i++){
        cin>>f[i];
        if(f[i]==-1)root=i;
    }
    for(int i=0;i<N;i++)
        if(!vis[i])
            DFS(i);
    printf("%.2f %d",P*pow(1+r,ans1),ans2);
}