#include<iostream>
using namespace std;

int N,M,K,Nv;
int num[10005],vis[10005];
struct Node{
    int l,r;
}Edge[10005];
bool check(){
    fill(vis,vis+N,0);
    for(int i=0;i<Nv;i++)
        vis[num[i]]=1;
    for(int i=0;i<M;i++)
        if(!vis[Edge[i].l]&&!vis[Edge[i].r])
            return false;
    return true;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++)
        cin>>Edge[i].l>>Edge[i].r;
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>Nv;
        for(int j=0;j<Nv;j++)
            cin>>num[j];
        if(check())cout<<"Yes\n";
        else cout<<"No\n";
    }
}