//11:17 - 11:33 - 25分
//DFS/BFS
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> V[100005];
bool isRetailer[100005]={};
bool vis[100005]={};
int N,K,num;
double price,r,ans=0;
void DFS(int i,double p){
    vis[i]=true;
    if(isRetailer[i])ans+=p*V[i][0];
    else{
        p=(1+r)*p;
        for(int j=0;j<V[i].size();j++)
            if(!vis[V[i][j]])
                DFS(V[i][j],p);
    } 
    p=p/(1+r);
}
int main(){
    cin>>N>>price>>r;
    r=r/100;
    for(int i=0;i<N;i++){
        cin>>K;
        if(K==0){
            cin>>num;
            isRetailer[i]=true;
            V[i].push_back(num);
        }
        else{
            for(int j=0;j<K;j++){
                cin>>num;
                V[i].push_back(num);
            }
        }
    }
    DFS(0,price);
    printf("%.1f",ans);
}