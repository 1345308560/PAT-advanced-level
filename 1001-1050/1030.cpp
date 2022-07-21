// 14:15 - 14；41 AC
#include<iostream>
#include<algorithm>
#include<vector>
#define INF 0x7fffffff
using namespace std;
int N,M,S,D;
struct Node{
    int des,dis,cos;
    Node (int de,int di,int co){
        des=de;dis=di;cos=co;
    }
};
vector<Node> V[505];
vector<int> ans;
int path[505];
bool vis[505];
int dist[505];
int dis_cost[505];
void Dijkstra(int beg){
    for(int i=0;i<N;i++){
        vis[i]=false;
        dist[i]=INF;
        dis_cost[i]=INF;
        path[i]=i;
    }
    dist[beg]=0;
    dis_cost[beg]=0;
    for(int i=0;i<N;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<N;j++){
            if(!vis[j]&&dist[j]<MIN){
                u=j;
                MIN=dist[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int des=V[u][j].des;
            int dis=V[u][j].dis;
            int cos=V[u][j].cos;
            if(!vis[des]&&dist[u]+dis<dist[des]){
                dist[des]=dist[u]+dis;
                dis_cost[des]=dis_cost[u]+cos;
                path[des]=u;
            }
            else if(!vis[des]&&dist[u]+dis==dist[des]&&dis_cost[u]+cos<dis_cost[des]){
                dis_cost[des]=dis_cost[u]+cos;
                path[des]=u;
            }
        }
    }
}

int main(){
    cin>>N>>M>>S>>D;
    for(int i=0;i<M;i++){
        int c1,c2,dis,cos;
        cin>>c1>>c2>>dis>>cos;
        Node temp(c2,dis,cos);
        Node temp2(c1,dis,cos);
        V[c1].push_back(temp);
        V[c2].push_back(temp2);
    }
    Dijkstra(S);
    int i_ans=D;
    while(1){
        ans.push_back(D);
        if(D==S)break;
        D=path[D];
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<" ";
    cout<<dist[i_ans]<<" "<<dis_cost[i_ans];
}