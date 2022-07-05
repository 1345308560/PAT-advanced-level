#include<iostream>
#include<vector>
#define INF 0x7fffffff
using namespace std;
int N,M,C1,C2;

struct Node{
    int num;
    int weight;
};
vector<Node> mp[405];

int v[405]={0};
int dis[405];
bool vis[405];
int road[405];// 到达某个节点的最短路个数
int MAXV[405];

void Dijkstra(int beg){

    for(int i=0;i<405;i++)dis[i]=INF;
    for(int i=0;i<405;i++)vis[i]=false;
    for(int i=0;i<405;i++)road[i]=0;
    for(int i=0;i<405;i++)MAXV[i]=v[i];

    dis[beg]=0;
    road[beg]=1;

    for(int i=0;i<N;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<N;j++){
            if(vis[j]==false&&dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<mp[u].size();j++){
            int newV=mp[u][j].num;
            int newW=mp[u][j].weight;
            if(vis[newV]==false&&dis[u]+newW<dis[newV]){
                dis[newV]=dis[u]+newW;
                road[newV]=road[u];
                MAXV[newV]=v[newV]+MAXV[u];
            }
            else if(vis[newV]==false&&dis[u]+newW==dis[newV]){
                road[newV]+=road[u];
                MAXV[newV]=max(MAXV[newV],v[newV]+MAXV[u]);
            }
        }
    }

}

int main(){
    cin>>N>>M>>C1>>C2;
    for(int i=0;i<N;i++)cin>>v[i];
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Node temp;temp.num=b;temp.weight=c;
        mp[a].push_back(temp);
        Node temp2;temp2.num=a;temp2.weight=c;
        mp[b].push_back(temp2);
    }
    Dijkstra(C1);
    cout<<road[C2]<<" "<<MAXV[C2];
}